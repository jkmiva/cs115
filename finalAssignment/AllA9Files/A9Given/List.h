// File: List.h
// CMPT 115 Assignment 9 (2015-2016)
// Synopsis: Defines the interface for the following ADTs
//   List
//   Iterator

#include "Element.h"

#ifndef _LIST_H_
#define _LIST_H_

struct ListNode {
  Element data;  // stores a pointer to data in node
  ListNode *next; // reference to next node in list
};

struct List {
  ListNode *head;  // reference to the first node in the list
  int numElements; // the number of nodes in the list
};

struct Iterator {
  ListNode *cur; // a reference to the current node in the traversal
};


// createList()
// post:  a new list is allocated
// return: reference to the new list

List *createList();

// createIterator(l)
// pre: l is a reference to a list
// post: allocates a new Iterator
// return: referecne to the new iterator
Iterator *createIterator(List *l);

//ACCESSORS

// isEmpty(l)
// pre: l is a reference to a List
//return: true if the list is empty
bool isEmpty(List *l);

// getNumElements(l)
// pre: l is a reference to a List
// return: the number of elements in the list
int getNumElements(List *l);

//MUTATORS

// deleteHead(l,elt)
// delete the head element of the list
// pre: l is a reference to a List
// pre: elt is a reference to an element
// post: the first element is removed from the list. 
//       el stores a reference to the removed element.
// return: true if successful, false otherwise.
bool deleteHead(List *l, Element *elt);

// insert(l,d)
// pre: l is a reference to a List
//      d is a reference to an element
// post: The data is added to the end of the list
// return: true if successful, false iotherwise
bool insert(List *l, Element dataIn);

// remove(l,d)
// pre: l is a reference to a List
//      d is a reference to an Element
// post: if d is in the list, then it has been removed
// return: true if the element was removed, false otherwise
bool remove(List *l, Element toRemove);

// destroyList(it)
// pre: it is a reference to a list
// post: the iterator is deallocated
void destroyList(List *l);

// Iterator's ACCESSORS
// hasNext(it)
// pre: it is a reference to an iterator
// return: true if there are more elements to look at
bool hasNext(Iterator *it);

// iterator's MUTATORS
// next(it)
// pre: it is a reference to an iterator
// post: the iterator is advanced
// return: the first yet unseen element 
Element next(Iterator *it);

// destroyIterator(it)
// pre: it is a reference to an iterator
// post: the iterator is deallocated
void destroyIterator(Iterator *it);

#endif

