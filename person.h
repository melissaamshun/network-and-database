
#ifndef PERSON_H
#define PERSON_H

#include "contact.h"
#include "date.h"
#include "misc.h"
#include <fstream>
#include <string>
#include <vector>

class Person {
  friend class Network;

private:
  string f_name;
  string l_name;
  Date *birthdate;
  Email *email;
  Phone *phone;
  std::vector<Person*> myfriends;
  // the following two attributes are used in the linked list.
  Person *next;
  Person *prev;

public:
  Person();
  ~Person();
  Person(string filename);
  Person(string f_name, string l_name, string b_date, string email,
         string phone);
  void print_person();
  string get_name() const;
  string get_lname();
  Date *get_birthdate() const;
  void set_person();
  void set_person(string filename);
  bool operator==(const Person &rhs);
  bool operator!=(const Person &rhs);
  void makeFriend(Person* newFriend);
};

#endif