
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
// TODO: You may need to add other libraries here!
using namespace std;

class Date {
  string date;
  string numericDate;

public:
  Date(string date);
  string get_date(string style) const;
  void print_date(string style);
  bool operator==(const Date& rhs);
};

#endif