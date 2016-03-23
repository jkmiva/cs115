/***************************************************************************
 Week 11 assignment
 Name: Huang Jiaming
 Student ID: 11207964
 NSID: jih211
 lecture session: Michael C. Horsch / Garrett
 ****************************************************************************/

// File: FrequencyList.cc
// CMPT 115 Assignment 9 (2015-2016)
// Synopsis: Defines the implementation for the FrequencyList ADT


#include "FrequencyList.h"
#include "Frequency.h"
#include "List.h"
#include "TreeNode.h"

#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

// CONSTRUCTORS

// createFrequencyList(message)
// create the input list for the Huffman algorithm.
// each node of the list contains a one node Tree.
// the data stored in each Tree is a Frequency.
// Pre: message:: refToChar, the message to count frequencies within
// Return: a reference to the generated list.
// post:  a new list is allocated
// return: reference to the new list

FrequencyList *createFrequencyList(const char* message){
  if (message == NULL) 
  {
    cerr << "Error in createFrequencyList(): NULL message!" << endl;
    return NULL;
  }

  // TODO: complete this function
	int counts[ASCII_SIZE];
	for (int i = 0; i < ASCII_SIZE; i++) {
		counts[i] = 0;
	}
	
	for (size_t j = 0; j < strlen(message); j++) {
		counts[(int)message[j]]++;
	}
	List* list = createList();
	for (int i = 0; i < ASCII_SIZE; i++) {
		if (counts[i] != 0) {
			TreeElement frequency = createFrequency((char)i, counts[i]);
			Element treeNode = createTreeNode(frequency);
			insert(list, treeNode);
		}
	}
	FrequencyList *freqList = new FrequencyList;
	freqList->freqs = list;
	return freqList;
}


// remove the smallest frequency tree from the list
// Pre: l is a list containing Trees of Frequencies.
// Post: the tree with smallest frequency has been removed
//       from the list.
// return: the Tree with smallest frequency in List l.
//         Will return NULL if the list was empty.
TreeNode *remove_smallest(FrequencyList *l){
  if (l == NULL) {
    cerr << "Error in remove_smallest: given NULL list" 
      << "  Returning NULL, but anything could happen."
      << endl;
    return NULL;
  }
  
  // TODO: complete this function
	//ListNode *smallest = l->freqs->head;
	Iterator *iterator = createIterator(l->freqs);
	//int tempSmallest = smallest->data->data->count;
	Element a;
	Element temp = l->freqs->head->data;
	while (hasNext(iterator)) {
		a = next(iterator);
		if (a->data->count < temp->data->count)
			temp = a;
	}
	remove(l, temp);
	return temp;

}



// destroyFrequencyList(it)
// pre: it is a reference to an iterator
// post: the iterator is deallocated
void destroyFrequencyList(FrequencyList *l) {
  if (l == NULL) {
    cerr << "Error in destroyFrequencyList(): given NULL list" 
      << endl;
    return;
  }

  if (l->freqs != NULL) {
    destroyList(l->freqs);
  }
  delete l;
}




//ACCESSORS

// isEmpty(l)
// pre: l is a reference to a FrequencyList
// return: true if l is empty
bool isEmpty(FrequencyList *l){
  if (l == NULL) {
    cerr << "Error in isEmpty(): given NULL list" 
	 << "  Returning true, but anything could happen."
      << endl;
    return true;
  }
  return isEmpty(l->freqs);
}

// getNumElements(l)
// pre: l is a reference to a FrequencyList
// return: the number of elements in the list
int getNumElements(FrequencyList *l){
  if (l == NULL) {
    cerr << "Error in getNumElemnts(): given NULL list" 
	 << "  Returning 0, but anything could happen."
      << endl;
    return 0;
  }
  return getNumElements(l->freqs);
}

//MUTATORS

// deleteHead(l,elt)
// delete the head element of the list
// pre: l is a reference to a FrequencyList
// pre: elt is a reference to an element
// post: the first element is removed from the list. 
//       el stores a reference to the removed element.
// return: true if successful, false otherwise.
bool deleteHead(FrequencyList *l, Element *elt){
  if (l == NULL) {
    cerr << "Error in deleteHead(): given NULL list" 
	 << "  Returning false, but anything could happen."
      << endl;
    return false;
  }
  return deleteHead(l->freqs, elt);
}

// insert(l,d)
// pre: l is a reference to a FrequencyList
//      d is a reference to an element
// post: The data is added to the end of the list
// return: true if successful, false iotherwise
bool insert(FrequencyList *l, Element dataIn){
  if (l == NULL) {
    cerr << "Error in insert(): given NULL list" 
	 << "  Returning false, but anything could happen."
      << endl;
    return false;
  }
  return insert(l->freqs, dataIn);
}

// remove(l,d)
// pre: l is a reference to a FrequencyList
//      d is a reference to an Element
// post: if d is in the list, then it has been removed
// return: true if the element was removed, false otherwise
bool remove(FrequencyList *l, Element toRemove){
  if (l == NULL) {
    cerr << "Error in remove(): given NULL list" 
	 << "  Returning false, but anything could happen."
      << endl;
    return false;
  }
  return remove(l->freqs,toRemove);
}


// eof

