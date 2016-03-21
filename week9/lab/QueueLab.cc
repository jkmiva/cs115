/***************************************************************************
 Week 10 assignment
 Name: Huang Jiaming
 Student ID: 11207964
 NSID: jih211
 lecture session: Michael C. Horsch / Garrett
 ****************************************************************************/

// file: Queue.cc
// CMPT 115

#include "Element.h"
#include "QueueLab.h"
#include <iostream>


// Algorithm createQueue(cap)
// Pre: cap :: integer, the capacity of the new Queue
// Post: allocates space for the Queue, total of cap Elements
// Return: a reference to the new Queue
Queue *createQueue(int capacity) {
	Queue *newQueue = new Queue;
	newQueue->elts = new Element[capacity];
	newQueue->head = 0;
	newQueue->numElements = 0;
	newQueue->capacity = capacity;
 	return newQueue;
}

// Algorithm destroyQueue()
// Post: deallocates space used by the Queue
void destroyQueue(Queue *q) {
	delete [] q->elts;
	delete q;
}

// Algorithm enqueue(q,e)
// Pre: q :: reference to a Queue
//      e :: Element
// Post: Stores e in q
// Return: true if successful, false if queue is already full

bool enqueue(Queue *q, Element e) {
	if(q->numElements < q->capacity){
		q->elts[(q->head + q->numElements)%(q->capacity)] = e;
		//q->head = ((q->head)+1)%(q->capacity);
		(q->numElements)++;
		return true;

	}
	else return false;
}

// Algorithm dequeue(q,e)
// Pre: q :: reference to Queue
//      e :: reference to Element
// Post: copies data to *e, and removes it from queue
// Return: true if successful, false if queue is already empty

bool dequeue(Queue *q, Element *e) {
	if(q->numElements == 0)
		return false;
	else{
		*e = q->elts[q->head];
		q->head = ((q->head)+1)%(q->capacity);
		(q->numElements)--;
		return true;
	}
}

// Algorithm queueSize(q)
// Pre: q :: reference to a Queue
// Return: the number of elements in the queue
int queueSize(Queue *q) {
	return q->numElements;
 // return 0;
}

// Algorithm queueEmpty(q)
// Pre: q :: reference to a Queue
// Return: true if the queue is empty, false otherwise
bool queueEmpty(Queue *q) {
	if(q->numElements == 0)
		return true;
 	else return false;
}


// Algorithm queueFull(q)
// Pre: q :: reference to a Queue
// Return: true if the queue is full, false otherwise
bool queueFull(Queue *q) {
	if(q->numElements == q->capacity)
		return true;
 	else return false;
}


// end of file

