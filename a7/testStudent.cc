/***************************************************************************
 Week 8 assignment
 Name: Huang Jiaming
 Student ID: 11207964
 NSID: jih211
 lecture session: Michael C. Horsch / Garrett
 ****************************************************************************/
#include <iostream>
#include <cstring>
#include "Student.h"
using namespace std;

int main(){
	Student *newStudent = readStudentRecordFromConsole();
	cout<<"test displayStudentRecord() function, the initial finalLetter is 'X',initial finalNumeric is 0."<< endl;
	displayStudentRecord(newStudent);
	cout<<"test calculateCourseGrade() function"<<endl;
	float finalNumeric = calculateCourseGrade(newStudent);
	cout << "numeric final is: " << finalNumeric <<endl;
	cout << "After calculating the final grade, Student Record is:" << endl;
	displayStudentRecord(newStudent);
	cout<< "test displayFinalGrade() function"<< endl;
	displayFinalGrade(newStudent);
	cout<< "test key() function"<<endl;
	cout<< "studentNumber is: "<<key(newStudent) << endl;
	cout<<"test changeAssignmentGradeForStudent() function, add 10 points to A3,now A3 should be 93."<<endl;
	cout<<"test changeExamGradeForStudent() function, add 5 points to final, final should be 95."<<endl;
	changeAssignmentGradeForStudent(newStudent, 3, 10);
	changeExamGradeForStudent(newStudent, 'F', 5);
	finalNumeric = calculateCourseGrade(newStudent);
	cout<< "new numeric final is: "<< finalNumeric <<endl;
	cout<< "new student record is: "<<endl;
	displayStudentRecord(newStudent);
	cout<< "test displayFinalGrade() again, new final Grade is"<<endl;
	displayFinalGrade(newStudent);
	destroyStudentRecord(newStudent);
	return 0;
}
