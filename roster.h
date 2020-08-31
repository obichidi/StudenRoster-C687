#pragma once


#include "student.h"



using namespace std;

class Roster {

private:
    int lastIndex = -1;
    const static int numStudents = 5;
    Student* ClassRosterArray[numStudents] = {0,0,0,0,0};
    

public:
  
   
    
   
    Roster();

   

    
    void ParseAdd( string studentData);

    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    void remove(string studentID);

    void printAll();

    void printAverageDaysInCourse(string studentID);

    void printInvalidEmails();

    void printByDegreeProgram(DegreeProgram degreeProgram);

    ~Roster();

};


