/***************************************************************************
 Week 8 assignment
 Name: Huang Jiaming
 Student ID: 11207964
 NSID: jih211
 lecture session: Michael C. Horsch / Garrett
 ****************************************************************************/
#include <iostream>
#include <cstdint>
#include <cassert>
using namespace std;


/****************************************************
 * 
 * 
 * 
 * please add '-std=c++11' in the compile command      <<<<<<<---------
 * 
 * 
 * 
 * **************************************************/
 
uint64_t fib(int n){
//pre::n: to calculate the nth fibonacci number
//post: nothing
//return: the nth fibonacci number
	if (n < 2)
		return n;
	return fib(n-1) + fib(n-2);
}

uint64_t fib2(int n, uint64_t& prev){ // linear complexity
//pre::n: to calculate the nth fibonacci number
//	   prev: the (n-1)th finonacci number
//post: nothing
//return: the nth fibonacci number
	if (n == 0){
		prev = 1;
		return 0;
	}
	uint64_t prevPrev;
	prev = fib2(n-1, prevPrev);
	return prevPrev + prev;
}

uint64_t moo(int n){
//pre::n: to calculate the nth moosonacci number
//post: nothing
//return: the nth moosonacci number
	if (n < 2)
		return n;
	if (n == 2)
		return 1;
	return moo(n-1)+moo(n-2)+moo(n-3);
}

int counter(char* arr,char c, int i){
//pre:: arr: a c string to be examined
//		c  : character
//		i  : index of arr
//post: nothing
//return: the number of times a letter c occurs in string arr starting at index i
	if (arr[i] == '\0')
		return 0;
	int num = 0;
	if (arr[i] == c)
		num++;
	return num + counter(arr, c, i+1);
}

int main(){
	uint64_t prev;
	assert(fib(5)==5);
	cout<<"fib(5) = "<<fib(5)<<endl;
	cout<<"fib2(45) = "<<fib2(45, prev)<<endl;
	assert(moo(6)==13);
	cout<<"moo(6) = "<<moo(6)<<endl;
	char a[] = "bilibili";
	int num = counter(a, 'i', 1);
	assert(4 == num);
	cout<<"number of 'i' in \"bilibili\" starting at index 1 is: "<< num <<endl;
	return 0;
}
