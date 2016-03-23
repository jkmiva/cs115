// File: copy.cc
// CMPT 115 Assignment 9 (2015-2016)
// Synopsis: Implements a convenient function to copy strings safely


#include <cstring>
#include <iostream>
using namespace std;

// Algorithm copy(s)
//   Pre: s :: refToChar
//   Post:  memory allocated on heap to store a copy
//   Return: reference to new string
char *copy(char *s) {
  if (s == NULL) {
    cerr << "Error in copy(): given NULL string to copy."  << endl;
  }
  char *temp = new char[strlen(s)+1];
  strcpy(temp,s);
  return temp;
}

// eof
