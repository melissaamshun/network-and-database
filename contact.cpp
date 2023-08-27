
#include "contact.h"
#include <string>
// TODO: Add needed libraries!

Email::Email(string type, string email_addr) {
  // TODO: Complete me!
  this->email_addr = email_addr;
  this->type = type;
}

void Email::set_contact() {
  // TODO: Do not change the prompts!
  std::cout << "Enter the type of email address: ";
  // some code here
  std::cin >> type;
  std::cout << "Enter email address: ";
  // some code here
  std::cin >> email_addr;
  // ARe you supposed to call constructor here?
}

string Email::get_contact(string style) {
  // Note: We have default argument in declaration and not in definition!
  if (style == "full")
    // return + type + email_addr;
    return "(" + type + ") " + email_addr;
  else
    return email_addr;
}

void Email::print() {
  // Note: get_contact is called with default argument
  std::cout << "Email " + Email::get_contact() << endl;
}

Phone::Phone(string type, string phone_number) {
  // TODO: It is possible that num includes "-" or not, manage it!
  // TODO: Complete this method!
  // Note: We don't want to use C++11! stol is not valid!
  // The code has been covered in the discussion session
  this->type = type;
  if (phone_number.length() == 12) {
    this->phone_num = phone_number;
  } else if (phone_number.length() == 10) {
    this->phone_num = phone_number.substr(0, 3) + "-" +
                      phone_number.substr(3, 3) + "-" +
                      phone_number.substr(6, 4);
  }
  /* Note: Understand your own TA's bug!
   * This code has a bug, can you understand why? no
  long int area_code = atoi(num.substr(0, 3).c_str());
  long int  number = atoi(num.substr(3).c_str());
  this->phone_num = area_code*10000000 + number;
  // Guess: putting int into string
  */
}

void Phone::set_contact() {
  // TODO: Complete this method
  // Use the same prompts as given!
  std::cout << "Enter the type of phone number: ";
  std::cin >> type;
  std::cout << "Enter the phone number: ";
  std::cin >> phone_num;
}

string Phone::get_contact(string style) {
  // TODO: Complete this method, get hint from Email
  // The code has been covered in discussion session
  if (style == "full")
    // return  + type + phone_num;
    return "(" + type + ") " + phone_num;
  else
    return phone_num;
  /* Note: Understand your own TA's bug!
   * This code has a bug, can you understand it!
  int x1 = (phone_num/10000000);
      int x2 = ((phone_num)/10000)%1000;
      int x3 = phone_num%10000;
    // Guess: phone_num is string
  */
}

void Phone::print() {
  // Note: get_contact is called with default argument
  std::cout << "Phone " + Phone::get_contact() << endl;
}