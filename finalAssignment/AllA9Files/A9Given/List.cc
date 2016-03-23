/***************************************************************************
 Week 11 assignment
 Name: Huang Jiaming
 Student ID: 11207964
 NSID: jih211
 lecture session: Michael C. Horsch / Garrett
 ****************************************************************************/

// File: List.cc
// CMPT 115 Assignment 9 (2015-2016)
// Synopsis: Defines the implementations for the following ADTs
//   List
//   Iterator

#include <cstdlib>
#include <iostream>
#include "List.h"

using namespace std;

// CONSTRUCTORS

// createList()
// post:  a new list is allocated
// return: reference to the new list

List *createList(){
  List *l = new List;
  l->head = NULL;
  l->numElements = 0;
  return l;
}


// createNode(d)
// pre: d is a reference to an Element
// post:  a new listNode is allocated
// return: reference to the new listNode

ListNode *createNode(Element dataIn){
  ListNode *n = new ListNode;
  n->data = dataIn;
  n->next = NULL;
  return n;
} 


// createIterator(l)
// pre: l is a reference to a list
// post: allocates a new Iterator
// return: referecne to the new iterator
Iterator *createIterator(List *l){
  // check error condition first
  if (l == NULL) {
    cerr << "Error in createIterator(): given a NULL list!" << endl;
    return NULL;
  }

  // non-error behaviour starts here
  Iterator *it = new Iterator;
  it->cur = l->head;
  return it;
}

//ACCESSORS

// isEmpty(l)
// pre: l is a reference to a List
//return: true if the list is empty
bool isEmpty(List *l){
  // check error condition first
  if (l == NULL) {
    cerr << "Error in isEmpty(List): given a NULL list!" 
         << "  Returning true, but anything could happen!"
         << endl;
    return true;
  }
  // non-error behaviour starts here
  return (l->numElements == 0);
}

// getNumElements(l)
// pre: l is a reference to a List
// return: the number of elements in the list
int getNumElements(List *l){
  // check error condition first
  if (l == NULL) {
    cerr << "Error in getNumElements(List): given a NULL list!" 
         << "  Returning 0, but anything could happen!"
         << endl;
    return 0;
  }
  // non-error behaviour starts here
  return l->numElements;
}

//MUTATORS

// deleteHead(l,elt)
// delete the head element of the list
// pre: l is a reference to a List
// pre: elt is a reference to an element
// post: the first element is removed from the list. 
//       el stores a reference to the removed element.
// return: true if successful, false otherwise.
bool deleteHead(List *l, Element *elt){
  // check error condition first
  if (l == NULL) {
    cerr << "Error in deleteHead(List): given a NULL list!" 
         << "  Returning false, but anything could happen!"
         << endl;
    return false;
  }

  // non-error behaviour starts here
  if (l->head==NULL){
    return false;
  } 
  else {
    *elt = l->head->data;
    ListNode *temp = l->head;
    l->head = l->head->next;
    delete temp;
    l->numElements--;
    return true;
  }
}

// insert(l,d)
// pre: l is a reference to a List
//      d is a reference to an element
// post: The data is added to the end of the list
// return: true if successful, false iotherwise
bool insert(List *l, Element dataIn){
  // check error condition first
  if (l == NULL) {
    cerr << "Error in insert(List): given a NULL list!" 
         << "  Returning false, but anything could happen!"
         << endl;
    return false;
  }

  // non-error behaviour starts here
  ListNode *newNode = createNode(dataIn);
  if( newNode == NULL) return false;
  if (l->head == NULL) {
    l->head = newNode;
  } 
  else {
    ListNode *cur = l->head;
    while(cur->next != NULL) {
      cur = cur->next;
    }
    cur->next = newNode;
  }
  l->numElements++;
  return true;
}

// remove(l,d)
// pre: l is a reference to a List
//      d is an Element
// post: if d is in the list, then it has been removed
// return: true if the element was removed, false otherwise
bool remove(List *l, Element toRemove){
  // check error condition first
  if (l == NULL) {
    cerr << "Error in remove(List): given a NULL list!" 
         << "  Returning false, but anything could happen!"
         << endl;
    return false;
  }

  // TODO: complete this function
	ListNode *tempNode = l->head;
	
	while (tempNode->next) {
		if (tempNode->next->data == toRemove) {
			//ListNode *nodeToRemove = tempNode->next;
			tempNode->next = tempNode->next->next;
			//delete nodeToRemove->data;
			//delete nodeToRemove;
			l->numElements --;
			break;
		}
		tempNode = tempNode->next;
	}
	if (l->head->data == toRemove ) {
		tempNode = l->head;
		l->head = l->head->next;
		//delete tempNode->data;
		//delete tempNode;
		l->numElements --;
	}
	return true;
}

// Iterator's ACCESSORS
// hasNext(it)
// pre: it is a reference to an iterator
// return: true if there are more elements to look at
bool hasNext(Iterator *it){
  if (it == NULL) {
    cerr << "Error in hasNext(): given a NULL Iterator!" 
         << "  Returning false, but anything could happen!"
         << endl;
    return false;
  }
  // non-error behaviour starts here
  return (it->cur != NULL);
}

// iterator's MUTATORS
// next(it)
// pre: it is a reference to an iterator
// post: the iterator is advanced
// return: the first yet unseen element 
Element next(Iterator *it){
  if (it == NULL) {
    cerr << "Error in next(): given a NULL Iterator!" 
         << "  Returning NULL, but anything could happen!"
         << endl;
    return NULL;
  }
  // non-error behaviour starts here
  Element d = it->cur->data;
  it->cur = it->cur->next;
  return d;
}

// destroyList(it)
// pre: it is a reference to a List 
// post: the iterator is deallocated
void destroyList(List *l) {
  // check error condition first
  if (l == NULL) {
    cerr << "Error in destroyList(): given a NULL list!" 
         << endl;
    return;
  }
  // non-error behaviour starts here
  while (l->head != NULL) {
    ListNode *temp = l->head;
    l->head = l->head->next;
    delete temp;
  }
  delete l;
}

// destroyIterator(it)
// pre: it is a reference to an iterator
// post: the iterator is deallocated
void destroyIterator(Iterator *it) {
  if (it == NULL) {
    cerr << "Error in destroyIterator(): given a NULL Iterator!" 
         << endl;
    return;
  }
  // non-error behaviour starts here
  delete it;
}

// eof
