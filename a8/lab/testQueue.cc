/***************************************************************************
 Week 10 assignment
 Name: Huang Jiaming
 Student ID: 11207964
 NSID: jih211
 lecture session: Michael C. Horsch / Garrett
 ****************************************************************************/

#include "QueueLab.h"
#include "Element.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	Queue *q = createQueue(10);
	char input;
	int a;
	int num = 1;
	while(1){
		cout <<"Enter t to take a number, or c to call next number, or q to quit:"<<endl;
		cin >> input;
		if (input == 't' && queueFull(q)==false){
			enqueue(q,num);
			cout<<"you have number "<< num <<"."<<endl;
			num++;
		}
		if (input == 't' && queueFull(q)==true){
			cout<<"queue is full , can't take more number."<<endl;
		}
		if (input == 'c' && queueEmpty(q) == false){
			dequeue(q,&a);
			cout <<"The number "<< a << " should leave the line"<<endl;
		}
		if (input == 'c' && queueEmpty(q) == true){
			cout <<"queue is empty, can't call more number."<<endl;
		}
		if (input == 'q')
			break;
	}
	return 0;
}
