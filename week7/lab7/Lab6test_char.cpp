// file: lab6test.cc
// start testing Lab 6 material
// This test assumes Element is char * (C-string)

#include <iostream>
#include "NodeList.h"

using namespace std;

int main(){
  // Test to see if the list operations 
  // work properly.

  char testStrings[4][25] = {"I'll","be","Bach.","*chortle*"};

  cout << "Testing!  Testing!  One, two, three..." << endl;

  //create list
  List *myList = createList();
  int testLimit = 4;
  
  // add some numbers to the list
  for (int i = 0; i < testLimit; i++) {
    insertTail(myList,testStrings[i]);
  }

  // testing deleteHead()
  // values should appear in the order they were inserted.
  char *data;
  while (lengthList(myList) > 0) {
    deleteTail(myList,&data);
    cout << "deleted " << data << endl;
  }
  
  destroyList(myList);

  cout << "Not with a whimper but with a !" << endl;
}
