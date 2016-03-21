/***************************************************************************
 Week 10 assignment
 Name: Huang Jiaming
 Student ID: 11207964
 NSID: jih211
 lecture session: Michael C. Horsch / Garrett
 ****************************************************************************/

#include "QueueAsn.h"
#include <iostream>
using namespace std;

Queue *createQueue(){
	List *innerList =  createList();
	Queue *newQueue = new Queue;
	newQueue -> inner = innerList;
	newQueue -> numElements = lengthList(innerList);
	return newQueue;
}


bool queueIsEmpty(Queue *q){
	if (emptyList(q->inner)==true)
		return true;
	else
		return false;
}


bool enQueue(Queue *q, Element data){

		insertHead(q->inner, data);
		q->numElements = lengthList(q->inner);
		return true;
}


int queueCount(Queue *q){
	return q->numElements;
}


bool deQueue(Queue *q, Element *dataOut){
	if (queueIsEmpty(q) == true)
		return false;
	head(q->inner,dataOut);
	deleteHead(q->inner);
	q->numElements = lengthList(q->inner);
	return true;
}


bool retrieve(Queue *q, Element *dataOut){
	if (queueIsEmpty(q) == true)
		return false;
	head(q->inner,dataOut);
	return true;
}


void destroyQueue(Queue *q){
	destroyList(q->inner);
	delete q;
}


