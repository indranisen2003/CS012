#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(0) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

/* Outputs to a single line all of the int values stored in the list, each separated by a space. 
   This function does NOT output a newline or space at the end.
*/
ostream & operator<<(ostream &out, const IntList &list) {
   IntNode* currNode = list.head;
   if (currNode != nullptr) {
      if (currNode -> next == nullptr) {
         out << currNode -> data;
      }
      else {
         out << currNode -> data << " " << currNode -> next;
      }
   }
   return out;
}

/* Helper function that passes in the address of a IntNode within an IntList and outputs
   all of integers within the IntList starting from this IntNode.
*/
ostream & operator<<(ostream &out, IntNode *node) {
   if (node != nullptr) {
      if (node -> next == nullptr) {
         out << node -> data;
      }
      else {
         out << node -> data << " " << node -> next;
      }
   }
   return out;
}

/* Returns true if the integer passed in is contained within the IntList.
   Otherwise returns false.
*/
bool IntList::exists(int num) const {
   IntNode* currNode = head;
   if (currNode != nullptr) {
      if (currNode -> next == nullptr) {
         return currNode -> data == num;
      }
      else {
         if (currNode -> data == num) {
            return true;
         }
         else {
            return exists(currNode -> next, num);
         }
      }
   }
   else {
      return false;
   }
}

/* Helper function that returns true if the integer passed in is contained within
   the IntNodes starting from the IntNode whose address is passed in.
   Otherwise returns false.
*/
bool IntList::exists(IntNode * node, int num) const {
   if (node -> next == nullptr) {
      return node -> data == num;
   }
   else {
      if (node -> data == num) {
         return true;
      }
      else {
         return exists(node -> next, num);
      }
   }
}
