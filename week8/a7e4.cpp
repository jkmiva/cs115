/***************************************************************************
 Week 8 assignment
 Name: Huang Jiaming
 Student ID: 11207964
 NSID: jih211
 lecture session: Michael C. Horsch / Garrett
 ****************************************************************************/
#include <iostream>
#include "Student.h"
#include "Element.h"
#include "List.h"
#include "Iterator.h"
using namespace std;

int main(){
//(1 mark) used the List ADT to create a new list.
	List *newList = createList();
	int num;
	cin >> num;
	cout << "there are "<< num << " student records."<<endl;
	Element *stuRecordArr = new Element[num];
	for (int i = 0; i<num; i++){
		stuRecordArr[i] = readStudentRecordFromConsole();
		if (insertTail(newList, stuRecordArr[i]) != true){	//(2 marks) used the List ADT to add Student records to the List.
			cout <<"initialize List error"<<endl;
			return -1;
		}
	}

//(2 marks) created and used a List Iterator to display every student record to the console.
cout << "******************************************************************"<<endl;
	Iterator *newIterator = createIterator(newList);
	Element temp;
	while(hasNext(newIterator)){
		temp = next(newIterator);
		displayStudentRecord(temp);
		cout<<"----------"<<endl;
	}
	destroyIterator(newIterator);

//(2 marks) created and used a List Iterator to display student numbers and grades to the console.
cout << "******************************************************************"<<endl;
	newIterator = createIterator(newList);
	float *finalNumeric = new float[num];
	float classSum = 0;
	int j = 0;
	while(hasNext(newIterator)){
		temp = next(newIterator);
		finalNumeric[j] = calculateCourseGrade(temp);
		classSum += finalNumeric[j++];
		displayFinalGrade(temp);
		cout<<"++++++++++"<<endl;
	}

//(2 marks) created and used a List Iterator to calculate a class average.
cout << "******************************************************************"<<endl;
	cout << "class average is: "<<classSum/(float)num<<endl;
	destroyIterator(newIterator);

//(6 marks) used a List Iterator to change a student assignment grade, and a student’s final exam grade. Full marks only if two different student records were used.
cout << "******************************************************************"<<endl;
	//int changeAssignment;
	//int changeFinal;
	//cout << "to change one's assignment grade, input his/her student number: "<<endl;
	//cin >> changeAssignment;
	//cout << "to change one's final grade, input his/her student number: "<<endl;
	//cin >> changeFinal;
	cout<<"adding 10 marks on A3 of a student whose student number is 11207964"<<endl
		<<"adding 5 marks on final grade of a student whose student number is 9527"<<endl;
	int indicator1 = 0, indicator2 = 0;
	newIterator = createIterator(newList);
	while(hasNext(newIterator)){
		temp = next(newIterator);
		if ( key(temp) == 11207964 ){
			changeAssignmentGradeForStudent(temp,3,10);
			calculateCourseGrade(temp);
			displayStudentRecord(temp);
			cout<<"----------"<<endl;
			indicator1 = 1;
		}
		if ( key(temp) ==  9527 ){
			changeExamGradeForStudent(temp, 'F', 5);
			calculateCourseGrade(temp);
			displayStudentRecord(temp);
			cout<<"----------"<<endl;
			indicator2 = 1;
		}
	}
	if (indicator1==0 || indicator2==0)
		cout<< "some record not found" <<endl;
	destroyIterator(newIterator);

//(1 mark) created and used a List Iterator to recalculate the class average.
cout << "******************************************************************"<<endl;
	newIterator = createIterator(newList);
	classSum = 0;
	int k = 0;
	while(hasNext(newIterator)){
		temp = next(newIterator);
		finalNumeric[k] = calculateCourseGrade(temp);
		classSum += finalNumeric[k++];
		//displayFinalGrade(temp);
	}
	cout << "new class average is: "<<classSum/(float)num<<endl;
	destroyIterator(newIterator);

//(1 mark) created and used a List Iterator to give every student 5 more marks on Assignment 5.
cout << "******************************************************************"<<endl;
	newIterator = createIterator(newList);
	cout<<"for test: after adding 5 more marks to every student on A5.new student records are as follows:"<<endl;
	int m = 0;
	classSum = 0;
	while(hasNext(newIterator)){
		temp = next(newIterator);
		changeAssignmentGradeForStudent(temp,5,5);
		finalNumeric[m] = calculateCourseGrade(temp);
		classSum += finalNumeric[m++];
		displayStudentRecord(temp);
		cout<<"----------"<<endl;
	}
	
//(1 mark) created and used a List Iterator to recalculate the class average.
cout << "******************************************************************"<<endl;
	cout<< "after adding 5 more marks to every student on A5 , the new class average is : "<< classSum/(float)num <<endl;
	destroyIterator(newIterator);
	
	
	delete []stuRecordArr;
	delete []finalNumeric;
	destroyList(newList);
	return 0;
}
