// File: FrequencyList.h
// CMPT 115 Assignment 9 (2015-2016)
// Synopsis: Defines the interface for the FrequencyList ADT


#include "List.h"
#include "LOCALE.h"

#ifndef _FREQUENCYLIST_H_
#define _FREQUENCYLIST_H_

// A frequency list is just a wrapper for a List.
// It has two special methods: 
//    create()
//    remove_smallest()
struct FrequencyList {
  List *freqs;
};


// createFrequencyList(message)
// create the input list for the Huffman algorithm.
// each node of the list contains a one node Tree.
// the data stored in each Tree is a Frequency.
// Pre: message:: refToChar, the message to count frequencies within
// Return: a reference to the generated list.
// post:  a new list is allocated
// return: reference to the new list
  
FrequencyList *createFrequencyList(const char message[]);



//ACCESSORS

// isEmpty(l)
// pre: l is a reference to a FrequencyList
//return: true if the list is empty
bool isEmpty(FrequencyList *l);

// getNumElements(l)
// pre: l is a reference to a FrequencyList
// return: the number of elements in the list
int getNumElements(FrequencyList *l);

//MUTATORS

// deleteHead(l,elt)
// delete the head element of the list
// pre: l is a reference to a FrequencyList
// pre: elt is a reference to an element
// post: the first element is removed from the list. 
//       el stores a reference to the removed element.
// return: true if successful, false otherwise.
bool deleteHead(FrequencyList *l, Element *elt);

// insert(l,d)
// pre: l is a reference to a FrequencyList
//      d is a reference to an element
// post: The data is added to the end of the list
// return: true if successful, false iotherwise
bool insert(FrequencyList *l, Element dataIn);

// remove(l,d)
// pre: l is a reference to a FrequencyList
//      d is a reference to an Element
// post: if d is in the list, then it has been removed
// return: true if the element was removed, false otherwise
bool remove(FrequencyList *l, Element toRemove);


// remove the smallest frequency tree from the list
// Pre: l is a list containing Trees of Frequencies.
// Post: the tree with smallest frequency has been removed
//       from the list.
// return: the Tree with smallest frequency in List l.
//         Will return NULL if the list was empty.
TreeNode *remove_smallest(FrequencyList *freqs);

// destroyFrequencyList(it)
// pre: it is a reference to an frequency list
// post: the iterator is deallocated
void destroyFrequencyList(FrequencyList *l);


#endif
