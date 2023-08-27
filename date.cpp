
#include "date.h"

Date::Date(string inp) {
  numericDate = inp;
  string monthNames[12] = {"January",   "February", "March",    "April",
                           "May",       "June",     "July",     "August",
                           "September", "October",  "November", "December"};
  string months[12] = {"01", "02", "03", "04", "05", "06",
                       "07", "08", "09", "10", "11", "12"};

  string temp = inp; // MM/DD/YYYY
  int delIndex = temp.find("/");
  string month = temp.substr(0, delIndex);
  string monthName;
  if (month.length() == 1) {
    month = "0" + month;
  }; // fix 1 or 01 issue
  for (int i = 0; i < 12; i++) {
    if (month == months[i]) {
      monthName = monthNames[i];
      break;
    }
  }

  temp = temp.substr(delIndex + 1); // DD/YYYY
  delIndex = temp.find('/');
  string day = temp.substr(0, delIndex);
  if (day.length() == 1) {
    day = "0" + day;
  }

  temp = temp.substr(delIndex+1); // YYYY
  string year = temp;

  this->date = monthName + " " + day + ", " + year;
}

string Date::get_date(string style) const {
  if (style == "Month D, YYYY") {
    return date;
  } else {
    return numericDate;
  }
}

void Date::print_date(string style) { cout << get_date(style) << endl; }

bool Date::operator==(const Date &rhs) {
  if ((this->get_date("")) == rhs.get_date("")) {
    return true;
  }
  return false;
}
