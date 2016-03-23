/***************************************************************************
 Week 11 assignment
 Name: Huang Jiaming
 Student ID: 11207964
 NSID: jih211
 lecture session: Michael C. Horsch / Garrett
 ****************************************************************************/

// File: Frequency.cc
// CMPT 115 Assignment 9 (2015-2016)
// Synopsis: Defines the implementation for the Frequency ADT

#include "Frequency.h"

#include <iostream>

using namespace std;

//CONSTRUCTOR
// pre: d is the character data being counted, 
//      c is the count.
// post: allocates memory for a new frequency record
// return: a reference to the new record
Frequency *createFrequency(char d, int c){
  // TODO: complete this function
    Frequency *freq = new Frequency;
    freq -> data = d;
    freq -> count = c;
    return freq;
}

// ACCESSORS

// getData(f)
// pre: f :: reference to a frequency record
// return: the character data
char getData(Frequency *f){
  // check error condition first
  if (f == NULL) {
    cerr << "Error in getData(Frequency): given NULL Frequency."
	 << "  Unrecoverable from here.  Application crashing immediately..."
	 << endl;
  }

  // normal behaviour starts here
  return f->data;
}

// getCount(f)
// pre: f :: reference to a frequency record
// return: the count
int getCount(Frequency *f){
  // check error condition first
  if (f == NULL) {
    cerr << "Error in getCount(Frequency): given NULL Frequency."
	 << "  Unrecoverable from here.  Application crashing immediately..."
	 << endl;
  }

  // normal behaviour starts here
  return f->count;
}

// MUTATORS

// setData(f)
// pre: f :: reference to a frequency record
// post: the data value has been set to d.
void setData(Frequency *f, char d){
  // check error condition first
  if (f == NULL) {
    cerr << "Error in setData(Frequency): given NULL Frequency."
	 << "  Unrecoverable from here.  Application crashing immediately..."
	 << endl;
  }

  // normal behaviour starts here
  f->data = d;
}

// setCount(f)
// pre: f :: reference to a frequency record
// post: the count value has been set to c.
void setCount(Frequency *f, int c){
  // check error condition first
  if (f == NULL) {
    cerr << "Error in setCount(Frequency): given NULL Frequency."
	 << "  Unrecoverable from here.  Application crashing immediately..."
	 << endl;
  }

  // normal behaviour starts here
  f->count = c;
}

// DESTRUCTOR
// pre: f :: reference to a frequency record
// post: deallocates frequency record
void destroyFrequency(Frequency *f) {
  // check error condition first
  if (f == NULL) {
    cerr << "Error in setCount(Frequency): given NULL Frequency."
	 << endl;
    return;
  }

  // normal behaviour starts here
  delete f;
}

// eof
