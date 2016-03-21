/***************************************************************************
 Week 8 assignment
 Name: Huang Jiaming
 Student ID: 11207964
 NSID: jih211
 lecture session: Michael C. Horsch / Garrett
 ****************************************************************************/
// file Student.h
// CMPT 115
// Assignment 7 Exercise 3
#ifndef STUDENT_H
#define STUDENT_H

struct Student {
  char *firstName;
  char *lastName;
  int studentNumber;
  char *NSID;
  float assignments[10];
  float midterm;
  float finalg;
  float finalNumeric;
  char finalLetter;
};



//////////////////////////////////////////////////////////////////
//Algorithm createStudentRecord()
//Pre: none
//Post: student record created
//Return: reference to newly created student record

Student *createStudentRecord();


//////////////////////////////////////////////////////////////////
//Algorithm destroyStudentRecord(s)
//Pre:	s :: refToStudent
//Post:	Student record s and fields deallocated
//Return:	nothing
//
void destroyStudentRecord(Student *s) ;


//////////////////////////////////////////////////////////////////
//Algorithm displayCString(s)
//Pre:  s :: refToChar
//Post:  s displayed to console, unless s is NULL
//Return: nothing
void displayCString(const char *s) ;


//////////////////////////////////////////////////////////////////
//Algorithm displayStudentRecord(s)
//Pre:  s :: refToStudent
//Post:  fields in s displayed to console
//Return: nothing

void displayStudentRecord(Student *s) ;
  

//////////////////////////////////////////////////////////////////
//Algorithm copyString(s)
//This is a helper function, to ensure that we never make a 
//mistake copying a C-string.  It's not part of the Student ADT Interface
//Pre:  s is a reference to a CString
//Post:   allocates new memory for a copy of s
//Return: reference to the new copy
char *copyString(const char *s) ;


//////////////////////////////////////////////////////////////////
//Algorithm readStudentRecordFromConsole()
//Pre:  nothing
//Post:  creates new student record and populates fields from console
//Return: refToStudent -- newly created student record
//
Student *readStudentRecordFromConsole() ;
  


//////////////////////////////////////////////////////////////////
//Algorithm changeAssignmentGradeForStudent(s, a, g)
//Pre:  s :: refToStudent
//    a :: Integer -- assignment number
//    g :: Integer -- amount to add to grade
//Post:  adds g marks to assignment number a for student s
//Return: nothing
void changeAssignmentGradeForStudent(Student *s, int a, int g) ;


//////////////////////////////////////////////////////////////////
//Algorithm changeExamGradeForStudent(s, x, e)
//Pre:  s :: refToStudent
//    x :: Char -- 'M' if midterm, 'F' if final
//    e :: Integer -- amount to add to exam grade
//Post:  adds e marks to exam (Midterm or Final) for student s
//Return: nothing
//
void changeExamGradeForStudent(Student *s, char x, int e) ;


/****************Assignment 7 Exercise 3 changes here****************/

//////////////////////////////////////////////////////////////////
//Algorithm calculateAverageGrade(s)
//Pre:  s :: refToStudent
//Post:  calculates student average final grade
//Return:  Float -- final average grade for student
//
float calculateCourseGrade(Student *s) ;

//////////////////////////////////////////////////////////////////
//Algorithm displayFinalGrade(s)
//Pre:	s :: refToStudent
//Post:	Nothing
//Return:	Nothing
//
void displayFinalGrade(Student *s);

//////////////////////////////////////////////////////////////////
//Algorithm key(s)
//Pre: s :: refToStudent
//Return: returns the student number
int key(Student *s);

#endif
