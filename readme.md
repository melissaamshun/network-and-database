https://github.com/melissaamshun/eeeeeeee.git

Team: 
  1. June Shao - 3502645580
  2. Melissa Shun - 8500174156
  3. Claire Yuan - 3545905379

Phase II

misc.cpp
  string codeName(): loops through each word of the first name and last name, changes it to lower case, and concactenates the words into a string

network.cpp
  

-------------------------------------------------------------------

EE 355 Final Project- Phase I

Class - CONTACT:
  contact.h:
    we made type a protected variable so that the subclasses (inherited types of the class) can access the type, since multiple subclasses have the type.
   added the virtual functions to the derived class and changed the type of phone_num to string rather than a long int because parsing strings is simpler (less bugs!) than using modulo to correct the format of the number.
  contact.cpp:
    get_contact(): returns the contact info, either with or without type
    set_contact(): sets the type and data for the contact
    print(): prints the contact by calling get_contact()
    Email() and Phone(): constructors are called and assign member variables type and email_addr/phone_nbr; Phone() also reformats the string phone_number based on the size of the string (ex: 1234567890 has size -> reformat; 123-456-7890 has size 12)
   
Class - PERSON:
  person.cpp:
    Person(): gets input to assign class members, allocates memory for email, phone, and birthdate
      instead of deriving, Person is composed with Email, Phone, and Date class ("has a")
    Person(string filename): reads from a file to get class members... uses set_person(filename)
    Person(string f_name, string l_name, string b_date, string email): initializes constructor with arguments for members
    ~Person(): destructor frees allocated mem
    get_name(): returns a string for the full name
    print(): prints the entire Person's info by calling the composite classes' print functions + get_name()
    set_person() and set_person(filename): takes input or reads from file, respectively, to create a new person object; distinction between email and phonenumbeer are handled by checking if a line in the file has an "@";    
  
  Class - DATE:
    date.h & date.cpp: templated from contact.h; added <string> standard library
      added members include the numeric data (MM/DD/YYYY) and the formatted date
      functions to print the date (using get_date()) and compare between dates are added.

Class - NETWORK:
  network.h: updated with member functions, added constructors and destructor
  network.cpp:
    default constructor makes an empty DLL
    Network(filename): uses loadDB to create a DLL from file input
    ~Network: deallocates memory from DLL objects
    Person *search(Person *searchEntry): searches list by comparing a person in the list to the person referenced in the argument.
    Person *search(string fname, string lname): searches list and compares nodes with the first and last name
    print_lnames(string last): traverses list and compares last names of Persons to find a match; prints if found.
    loadDB(string filename): reads line-by-line through a given file and adds it to a new Person object; uses push_front to append to list.
    saveDB(string filename): prints to file by extracting data from Person and its compoa
    push_back(Person *newEntry): used push_front and just switched direction list propagates
    remove(string fname, string lname): uses search() then removes the Person if it exists in the list by freeing the allocated mem and reattaching the prev and next pointers      
  
Main Menu of Class NETWORK:
  1. saves the DLL to a new file using saveDB()
  2. loads the network from a file; creates DDL using loadDB()
  3. Allows you to add a new person by input; checks if said person already exists (no impersonation or fraud allowed here!) We check this my checking if the search function returns a null pointer.
  4. removes a person by searching for their first and last name and the remove method. 
  5. Prints out a list of people with the specified last name
  6. Allows users to add friends with each other. This is mutual, which means that both people become each other's friend and it is not one sided.
  7.  (not shown: used to debug; prints the entire list)

Sources:

I used this to see how to put the variable in constructor into the variable:
https://cplusplus.com/forum/general/13043/

I used this to help understand operator definition:
https://jalevine.bitbucket.io/notes/c++/2018/02/16/assignment-operators.html#:~:text=lhs%20refers%20to%20%E2%80%9Cleft%20hand,the%20right%20of%20the%20%3D%20operator.

I used this to understand this line (cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'):
https://stackoverflow.com/questions/25020129/cin-ignorenumeric-limitsstreamsizemax-n#:~:text=numeric_limits%3A%3Amax()%20sets%20the%20maximum%20number,number%20of%20characters%20to%20ignore.

Similarly, I used this to understand that group of lines that I mentioned above:
https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input

We used ChatGPT just to understand the line of cout << "33[3[3]3[]33][3]" (similar to that).

Code comments:
  /* Note: Understand your own TA's bug!
  This code has a bug, can you understand why? no
  long int area_code = atoi(num.substr(0, 3).c_str());
  long int  number = atoi(num.substr(3).c_str());
  this->phone_num = area_code*10000000 + number;
  // Guess: putting int into string
  */

  /* Note: Understand your own TA's bug!
  This code has a bug, can you understand it!
  int x1 = (phone_num/10000000);
      int x2 = ((phone_num)/10000)%1000;
      int x3 = phone_num%10000;
    // Guess: phone_num is string
  */

  Understanding cctype library header for codeName: https://cplusplus.com/reference/cctype/
