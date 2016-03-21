//
// Simple Lists: the list contains a pointer to the head node
//
// Ian McQuillan, Christopher Dutchyn, for CMPT115 2013
// Minor modifications for 2016 by mch
//


#include "List.h"
#include <cstdlib>

// CONSTRUCTOR and DESTRUCTOR
// create a new empty list
//   Pre: nothing
//   Post: memory is allocated for the new list record
//   Return: a reference to the new list
List *createList() {
  List *l;
  l = new List;
  l->head = NULL;
  l->count = 0;

  return l;
}

// destroy an existing list
//   Pre: l is a valid reference to a list
//   Post: memory for the list record is deallocated
//   Return: nothing
//   Bug: if the Element is not a primitive type, it might not be deallocated!
void destroyList(List *l) {
  Node* p = l->head;
  while (NULL != p) {
    Node* t = p->next;
    delete p;
    p = t;
  }
  delete l;
}


// STATUS
// check whether a list is empty
//  Pre: l is a valid reference to a list
//  Post: nothing
//  Return: true, if the list is empty, false otherwise
bool emptyList(List *l) {
  return (NULL == l->head);
}

// return the element count of a list
//  Pre: l is a valid reference to a list
//  Post: nothing
//  Return: the number of elements in the list
int lengthList(List *l) {
  return l->count;
}


// INSERTION -- return indicates success or failure
// insert the element into the list as the head
//  Pre: l is a valid reference to a list
//       e is an Element to be inserted
//  Post: the list has e at the front
//  Return: true, if the insertion worked, false otherwise
bool insertHead(List *l, Element e) {

  Node* n = new Node;
  if (NULL == n) {
    return false;
  }

  n->data = e;
  n->next = l->head;
  l->head = n;
  l->count += 1;

  return true;
}

// insert the element into the list as the tail
//  Pre: l is a valid reference to a list
//       e is an Element to be inserted
//  Post: the list has e at the end
//  Return: true, if the insertion worked, false otherwise
bool insertTail(List *l, Element e) {
  if (NULL == l->head) {
    return insertHead(l, e);
  }

  Node* n = new Node;
  if (NULL == n) {
    return false;
  }

  n->data = e;
  n->next = NULL;
  l->count += 1;

  Node* p = l->head;
  if (NULL == p) return false;

  while (NULL != p->next) {
    p = p->next;
  }
  p->next = n;

  return true;
}

// EXTRACTION -- return indicates success or failure
// return the element at the head of the list
//  Pre: l is a valid reference to a list
//       e is a reference to an Element
//  Post: the Element at the head of the list is copied to *e
//  Return: true, if the copy worked, false otherwise
bool head(List *l, Element *e) {
  if (NULL == l->head) {
    return false;
  }
  *e = l->head->data;
  return true;
}

// return the element at the tail of the list
//  Pre: l is a valid reference to a list
//       e is a reference to an Element
//  Post: the Element at the tail of the list is copied to *e
//  Return: true, if the copy worked, false otherwise
bool tail(List *l, Element *e) {
  if (NULL == l->head) {
    return false;
  }
  
  Node* p = l->head;
  if (NULL == p) return false;
  while (NULL != p->next) {
    p = p->next;
  }

  *e = p->data;
  return true;
}



// DELETION -- return indicates success or failure
// delete the element at the head of the list
//  Pre: l is a valid reference to a list
//  Post: the Element at the head of the list is removed from the list
//  Return: true, if the list was not empty, false otherwise
bool deleteHead(List *l) {
  if (NULL == l->head) {
    return false;
  }

  l->count -= 1;
  Node *p = l->head;
  l->head = p->next;
  p->next = NULL;
  delete p;
  return true;
}

// delete the element at the tail of the list
//  Pre: l is a valid reference to a list
//  Post: the Element at the tail of the list is removed from the list
//  Return: true, if the list was not empty, false otherwise
bool deleteTail(List *l) {
  if (NULL == l->head) {
    return false;
  }

  if (NULL == l->head->next) {
    return deleteHead(l);
  }

  l->count -= 1;
  Node *p = l->head;
  while (NULL != p->next->next) {
    p = p->next;
  }

  delete p->next;
  p->next = NULL;
  return true;
}



// end of file
