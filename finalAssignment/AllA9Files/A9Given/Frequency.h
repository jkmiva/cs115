// File: Frequency.h
// CMPT 115 Assignment 9 (2015-2016)
// Synopsis: Defines the interface for the Frequency ADT


#ifndef _Frequency_H_
#define _Frequency_H_

struct Frequency {
  char data; // the character being represented
  int count; // the number of occurrences of the character
};

// CONSTRUCTOR
// pre: d is the character data being counted, 
//      c is the count.
// post: allocates memory for a new frequency record
// return: a reference to the new record
Frequency *createFrequency(char d, int c);

// ACCESSORS

// getData(f)
// pre: f :: reference to a frequency record
// return: the character data
char getData(Frequency *f);

// getCount(f)
// pre: f :: reference to a frequency record
// return: the count
int getCount(Frequency *f);

// MUTATORS

// setData(f)
// pre: f :: reference to a frequency record
// post: the data value has been set to d.
void setData(Frequency *f, char d);

// setCount(f)
// pre: f :: reference to a frequency record
// post: the count value has been set to c.
void setCount(Frequency *f, int c);

// DESTRUCTOR
// pre: f :: reference to a frequency record
// post: deallocates frequency record
void destroyFrequency(Frequency *f);

#endif
