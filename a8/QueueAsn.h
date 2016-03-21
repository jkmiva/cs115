/***************************************************************************
 Week 10 assignment
 Name: Huang Jiaming
 Student ID: 11207964
 NSID: jih211
 lecture session: Michael C. Horsch / Garrett
 ****************************************************************************/

#include "List.h"

#ifndef QUEUEASN_H
#define QUEUEASN_H

struct Queue {
	List* inner;
	int numElements;
};

Queue *createQueue();

bool queueIsEmpty(Queue *q);

bool enQueue(Queue *q, Element data);

int queueCount(Queue *q);

bool deQueue(Queue *q, Element *dataOut);

bool retrieve(Queue *q, Element *dataOut);

void destroyQueue(Queue *q);



#endif
