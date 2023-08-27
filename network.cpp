#include "network.h"
#include "misc.h"
#include <fstream>
#include <limits>
#include <sstream>

Network::Network() {
  head = NULL;
  tail = NULL;
  count = 0;
}

Network::Network(string fileName) {
  // TODO: complete this method!
  // Implement it in one single line!
  // You may need to implement the load method before this!
  loadDB(fileName);
}

Network::~Network() {
  Person *ptr = head;

  // Iterate through list and free memory for each element
  while (ptr != NULL) {
    Person *to_delete = ptr;
    ptr = ptr->next;
    delete to_delete;
  }
}

Person *Network::search(Person *searchEntry) {
  // Searches the Network for searchEntry
  // if found, returns a pointer to it, else returns NULL
  // TODO: Complete this method
  Person *ptr = head;

  while (ptr != NULL) {
    if (*ptr == *searchEntry) {
      return ptr;
    }
    ptr = ptr->next;
  }
  return NULL;
}

Person *Network::search(string fname, string lname) {
  // New == for Person, only based on fname and lname
  // if found, returns a pointer to it, else returns NULL
  // TODO: Complete this method
  // Note: two ways to implement this, 1st making a new Person with fname and
  // lname and and using search(Person*), 2nd using fname and lname directly.
  Person *ptr = head;
  string targ_name = lname + ", " + fname;
  while (ptr != NULL) {
    if (ptr->get_name() == targ_name) {
      return ptr;
    }
    ptr = ptr->next;
  }
  return NULL;
}

void Network::print_lnames(string last) {
  Person *ptr = head;
  bool found = false;
  while (ptr != NULL) {
    if (ptr->get_lname() == last) {
      ptr->print_person();
      std::cout << "------------------------------" << endl;
      found = true;
    }
    ptr = ptr->next;
  }
  if (found == false) {
    std::cout << "Person not found! \n";
  }
}

void Network::loadDB(string filename) {
  // TODO: Complete this method
  ifstream fin;
  fin.open(filename.c_str());
  string line;
  int cnt = 0;
  string fn, ln, bd, l4, l5, email, phone;

  while (getline(fin, line)) {
    cnt++;
    switch (cnt) {
    case 1:
      fn = line;
      break;
    case 2:
      ln = line;
      break;
    case 3:
      bd = line;
      break;
    case 4:
      if (line.find("@") != string::npos) {
        email = line;
      } else {
        phone = line;
      }
      break;
    case 5:
      if (line.find("@") != string::npos) {
        email = line;
      } else {
        phone = line;
      }
      break;
    default:
      Person *newPerson = new Person(fn, ln, bd, email, phone);
      push_front(newPerson);
      cnt = 0;
      break;
    }
    /*

    f_name = fn;
    l_name = ln;
    // birthdate = new Date(bd);
    // from https://www.w3schools.blog/c-check-if-string-contains-substring
    if (l4.find("@") != string::npos) {
      email = l4;
      phone = l5;
    }
    else {
      email = l5;
      phone = l4;
    }
    Person *newPerson = new Person(fn, ln, bd, email, phone);
    push_front(newPerson);

    // Skip the rest of the dashes
    getline(fin, data);
    */
  }
  fin.close();
}

void Network::saveDB(string filename) {
  // TODO: Complete this method
  Person *temp = head;
  string name, dob, full_email, full_phone;
  // string filein = filename + ".txt";
  ofstream fout;
  fout.open(filename.c_str());
  fout << "------------------------------" << endl;
  while (temp != NULL) {
    name = temp->get_name();
    Date *bdte = temp->birthdate;
    dob = bdte->get_date("Month D, YYYY");
    Email *emladdr = temp->email;
    full_email = emladdr->get_contact("full");
    Phone *phnnmbr = temp->phone;
    full_phone = phnnmbr->get_contact("full");
    fout << name + "\n" + dob + "\n" + full_email + "\n" + full_phone + "\n";
    for (int i = 0; i < temp->myfriends.size(); i++) {
      Person *idx = temp->myfriends[i];
      string friendname = idx->get_name();
      string codename = codeName(friendname);
      fout << codename << endl;
      // std::cout << myfriends[i] << endl;
    }
    fout << "------------------------------" << endl;
    temp = temp->next;
  }
  fout.close();
}

void Network::printDB() {
  // Leave me alone! I know how to print!
  // Note: Notice that we don't need to update this even after adding to
  // Personattributes This is a feature of OOP, classes are supposed to take
  // care of themselves!
  std::cout << "Number of people: " << count << endl;
  std::cout << "------------------------------" << endl;
  Person *ptr = head;
  while (ptr != NULL) {
    ptr->print_person();
    std::cout << "------------------------------" << endl;
    ptr = ptr->next;
  }
}

void Network::push_front(Person *newEntry) {
  newEntry->prev = NULL;
  newEntry->next = head;

  if (head != NULL)
    head->prev = newEntry;
  else
    tail = newEntry;

  head = newEntry;
  count++;
}

void Network::push_back(Person *newEntry) {
  // Adds a new Person (newEntry) to the back of LL
  // TODO: Complete this method

  newEntry->prev = tail;
  newEntry->next = NULL;

  if (tail != NULL)
    head->prev = newEntry;
  else
    head = newEntry;

  tail = newEntry;
  count++;
}

bool Network::remove(string fname, string lname) {
  // TODO: Complete this method
  Person *p = search(fname, lname);

  // If person exists
  if (p != NULL) {
    if (p == head) {
      (p->next)->prev = NULL;
      head = p->next;
    } else if (p == tail) {
      (p->prev)->next = NULL;
      tail = p->prev;
    } else { // Person is somewhere in the middle of list
      (p->next)->prev = p->prev;
      (p->prev)->next = p->next;
    }
    delete p;
    count--;
    return true;
  }
  return false;
}

void Network::showMenu() {
  // TODO: Complete this method!
  // All the prompts are given to you,
  // You should add code before, between and after prompts!

  int opt;
  while (1) {
    std::cout << "\033[2J\033[1;1H";
    printMe("banner"); // from misc library

    std::cout << "Select from below: \n";
    std::cout << "1. Save network database \n";
    std::cout << "2. Load network database \n";
    std::cout << "3. Add a new person \n";
    std::cout << "4. Remove a person \n";
    std::cout << "5. Print people with last name  \n";
    std::cout << "6. Connect \n";
    std::cout << "\nSelect an option ... ";

    if (cin >> opt) {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cout << "Wrong option! " << endl;
      return;
    }

    // You may need these variables! Add more if you want!
    string fname, lname, fileName, bdate;
    cout << "\033[2J\033[1;1H";

    if (opt == 1) {
      // TODO: Complete me!
      cout << "Saving network database \n";
      cout << "Enter the name of the save file: ";

      cin >> fileName;
      saveDB(fileName);

      cout << "Network saved in " << fileName << endl;

    } else if (opt == 2) {
      // TODO: Complete me!
      cout << "Loading network database \n";
      // TODO: print all the files in this same directory that have
      // "networkDB.txt" format Take a look into sample_files.cpp
      cout << "Enter the name of the load file: ";

      cin >> fileName;

      // If file with name FILENAME does not exist:
      ifstream fin;
      fin.open(fileName.c_str());
      if (!fin) {
        cout << "File FILENAME does not exist!" << endl;
      }

      else {
        // If file is loaded successfully, also print the count of people in it:
        fin.close();
        loadDB(fileName);

        cout << "Network loaded from " << fileName << " with " << count
             << " people \n";
      }

    } else if (opt == 3) {
      // TODO: Complete me!
      // TODO: use push_front, and not push_back
      // Add a new Person ONLY if it does not exists!
      cout << "Adding a new person \n";

      string fname, lname, b_date, email_addr, email_type, phone_nbr,
          phone_type, e_buf, p_buf;
      cout << "First name: ";
      std::getline(std::cin, fname);
      cout << "Last name: ";
      std::getline(std::cin, lname);
      cout << "Birth date (format: <MM/DD/YYYY>): ";
      std::getline(std::cin, b_date);
      cout << "Email type: ";
      std::getline(std::cin, email_type);
      cout << "Email address: ";
      std::getline(std::cin, e_buf);
      email_addr = "(" + email_type + ") " + e_buf;
      cout << "Phone type: ";
      std::getline(std::cin, phone_type);
      cout << "Phone number: ";
      std::getline(std::cin, p_buf);
      phone_nbr = "(" + phone_type + ") " + p_buf;

      if (search(fname, lname) == NULL) {
        Person *newPerson =
            new Person(fname, lname, b_date, email_addr, phone_nbr);
        push_front(newPerson);
      }

    } else if (opt == 4) {
      // TODO: Complete me!
      // if found, cout << "Remove Successful! \n";
      // if not found: cout << "Person not found! \n";
      cout << "Removing a person \n";
      cout << "First name: ";
      std::getline(std::cin, fname);
      cout << "Last name: ";
      std::getline(std::cin, lname);

      bool rem = remove(fname, lname);
      if (rem == true) {
        cout << "Remove Successful! \n";
      } else {
        cout << "Person not found! \n";
      }

    } else if (opt == 5) {
      // TODO: Complete me!
      // print the people with the given last name
      // if not found: cout << "Person not found! \n";
      cout << "Print people with last name \n";
      cout << "Last name: ";
      string lname;
      cin >> lname;
      print_lnames(lname);
    } else if (opt == 6) {
      // TODO: Connect
      cout << "\033[2J\033[1;1H";
      cout << "Make friends:" << endl;
      string friend1[2];
      string friend2[2];

      cout << "Person 1" << endl;
      cout << "First Name:";
      getline(cin, friend1[0]);
      cout << "Last Name:";
      getline(cin, friend1[1]);

      Person *person1 = search(friend1[0], friend1[1]);

      if (person1 == NULL) {
        cout << "Person not found" << endl;
      } else {
        cout << "Person 2" << endl;
        cout << "First Name: ";
        getline(cin, friend2[0]);
        cout << "Last Name:";
        getline(cin, friend2[1]);

        Person *person2 = search(friend2[0], friend2[1]);

        if (person2 == NULL) {
          cout << "Person not found" << endl;
        } else {
          cout << endl;
          person1->print_person();
          cout << endl;
          person2->print_person();

          person1->makeFriend(person2);
          person2->makeFriend(person1);
        }
      }
    }
    /// TEST OPTIONS
    else if (opt == 7) {
      printDB();
    }

    else
      cout << "Nothing matched!\n";

    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "\n\nPress Enter key to go back to main menu ... ";
    string temp;
    std::getline(std::cin, temp);
    cout << "\033[2J\033[1;1H";
  }
}