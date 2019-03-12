#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

void flipString(string &s) {
   if (s.size() != 1 && s.size() != 0) {
      string str = s.substr(0, s.size() - 1);
      s = s.back();
      flipString(str);
      s += str;
   }
}





























s = help