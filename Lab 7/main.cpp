#include <iostream>
using namespace std;

#include "IntList.h"

int main() {

  //tests constructor, destructor, push_front, pop_front, display

   {
      cout << "\nlist1 constructor called" << flush;
      IntList list1;
      cout << "\npushfront 10" << flush;
      list1.push_front(10);
      cout << "\npushfront 20" << flush;
      list1.push_front(20);
      cout << "\npushfront 30" << flush;
      list1.push_front(30);
      cout << "\nlist1: " << flush;
      list1.display();
      cout << "\npop" << flush;
      list1.pop_front();
      cout << "\nlist1: " << flush;
      list1.display();
      cout << "\npop" << flush;
      list1.pop_front();
      cout << "\nlist1: " << flush;
      list1.display();
      cout << "\npop" << flush;
      list1.pop_front();
      cout << "\nlist1: " << flush;
      list1.display();
      cout << "\npushfront 100" << flush;
      list1.push_front(100);
      cout << "\npushfront 200" << flush;
      list1.push_front(200);
      cout << "\npushfront 300" << flush;
      list1.push_front(300);
      cout << "\nlist1: " << flush;
      list1.display();
      cout << endl;
      cout << "Calling list1 destructor..." << endl;
   }
   cout << "list1 destructor returned" << endl;
   
   // Test destructor on empty IntList
   {
      IntList list2;
      cout << "Calling list2 destructor..." << endl;
   }
   cout << "list2 destructor returned" << endl;
   
   return 0;
}
