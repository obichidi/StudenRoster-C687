#pragma once
#include "degree.h"
#include <iomanip>
#include "student.h"
#include<iostream>



using namespace std;



class Student {

public:
	const static int numDaysSize = 3;

	Student();

	Student(string studentID, string firstName, string lastName, string emailAddress,  int age, int numberOfDays[], DegreeProgram degreeProgram );
	 

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numberOfDays[numDaysSize];
	DegreeProgram degreeProgram;

public:
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int* GetNumberOfDays();
	DegreeProgram GetDegreeProgram();


	void SetStudentID(string studentID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmailAddress(string emailAddress);
	void SetNumberOfDays(int NumberOfDays[]);
	void SetDegreeProgran(DegreeProgram degreeprogram);
	void Print();

	~Student();

};


