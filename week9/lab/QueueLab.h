/***************************************************************************
 Week 10 assignment
 Name: Huang Jiaming
 Student ID: 11207964
 NSID: jih211
 lecture session: Michael C. Horsch / Garrett
 ****************************************************************************/

// file: Queue.h
// CMPT 115

#include "Element.h"

#ifndef _QUEUE_H_
#define _QUEUE_H_

struct Queue {
  Element *elts;		// the elements
  int head;			// index of front element
  int numElements;		// number of elements in queue
  int capacity;			// how many elements can be stored
};


// Algorithm createQueue(cap)
// Pre: cap :: integer, the capacity of the new Queue
// Post: allocates space for the Queue, total of cap Elements
// Return: a reference to the new Queue
Queue *createQueue(int);


// Algorithm destroyQueue()
// Post: deallocates space used by the Queue
void destroyQueue(Queue *);


// Algorithm enqueue(q,e)
// Pre: q :: reference to a Queue
//      e :: Element
// Post: Stores e in q
// Return: true if successful, false if queue is already full
bool enqueue(Queue *, Element);


// Algorithm dequeue(q,e)
// Pre: q :: reference to Queue
//      e :: reference to Element
// Post: copies data to *e, and removes it from queue
// Return: true if successful, false if queue is already empty
bool dequeue(Queue *, Element *);


// Algorithm queueSize(q)
// Pre: q :: reference to a Queue
// Return: the number of elements in the queue
int queueSize(Queue *);


// Algorithm queueEmpty(q)
// Pre: q :: reference to a Queue
// Return: true if the queue is empty, false otherwise
bool queueEmpty(Queue *);

// Algorithm queueFull(q)
// Pre: q :: reference to a Queue
// Return: true if the queue is full, false otherwise
bool queueFull(Queue *);

#endif

