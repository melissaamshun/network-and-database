
#include "misc.h"
#include <cctype>

void printMe(string type) {
  if (type == "banner") {
    char banner[] =
        "   ######## ########   #######        ##    ###    ##    ##         ########   #######   #######  ##    ## \n \
     ##    ##     ## ##     ##       ##   ## ##   ###   ##         ##     ## ##     ## ##     ## ##   ## \n \
     ##    ##     ## ##     ##       ##  ##   ##  ####  ##         ##     ## ##     ## ##     ## ##  ## \n \
     ##    ########  ##     ##       ## ##     ## ## ## ## ####### ########  ##     ## ##     ## ##### \n \
     ##    ##   ##   ##     ## ##    ## ######### ##  ####         ##     ## ##     ## ##     ## ##  ## \n \
     ##    ##    ##  ##     ## ##    ## ##     ## ##   ###         ##     ## ##     ## ##     ## ##   ## \n \
     ##    ##     ##  #######   ######  ##     ## ##    ##         ########   #######   #######  ##    ##\n";
    cout << endl << banner << endl << endl;
  }
}

string codeName(string str1) {

  int c_index = 0;
  while (str1.substr(c_index, 1) != ",") {
    c_index++;
  }
  string fname = str1.substr(c_index + 1);
  string lname = str1.substr(0, c_index);
  str1 = fname + lname;

  string n = "";
  int i = 0;
  while (str1[i]) {
    if (str1[i] != ' ') {
      str1[i] = tolower(str1[i]);
      n = n + str1[i];
    }
    i++;
  }
  return n;
  /*
  string fn, ln;
  int i = 0;
  while(str1[i]){
    if(str1[i] != ' '){
      str1[i] = tolower(str1[i]);
      fn = fn + str1[i];
    }
    i++;
  }
  i = 0;
  while(str2[i]){
    if(str2[i] != ' '){
      str2[i] = tolower(str2[i]);
      ln = ln + str2[i];
    }
    i++;
  }
  return fn + ln;
  */
}