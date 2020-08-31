#pragma once
#include"student.h"

using namespace std;

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < numDaysSize; i++) this->numberOfDays[i] = 0; 
	this->degreeProgram = DegreeProgram::SOFTWARE;
	
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numberOfDays[],DegreeProgram degreeProgram )
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < numDaysSize; i++) this->numberOfDays[i] = numberOfDays[i];

	this->degreeProgram = degreeProgram;

}

string Student::GetStudentID()
{
	return this->studentID;
}

string Student::GetFirstName()
{
	return this->firstName;
}

string Student::GetLastName()
{
	return this->lastName;
}

string Student::GetEmailAddress()
{
	return this->emailAddress;
}

int Student::GetAge()
{
	return this->age;
}

int* Student::GetNumberOfDays()
{
	return this->numberOfDays;
}

 DegreeProgram Student::GetDegreeProgram()
{
	return this->degreeProgram;

}



void Student::SetStudentID(string studentID)
{
	this->studentID = studentID;
}

void Student::SetFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::SetLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::SetEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::SetNumberOfDays(int NumberOfDays[])
{
	for (int i = 0; i < numDaysSize; i++)
		this->numberOfDays[i] = numberOfDays[i];


}

void Student::SetDegreeProgran(DegreeProgram degreeProgram)
{
	this->degreeProgram = degreeProgram;
}

void Student::Print()
{
	cout << this->GetStudentID() << '\n';
	cout << this->GetFirstName() << '\n';
	cout << this->GetLastName() << '\n';
	cout << this->GetEmailAddress() << '\n';
	cout << this->GetAge() << '\n';
	cout << this->GetNumberOfDays()[0] << '\n';
	cout << this->GetNumberOfDays()[1] << '\n';
	cout << this->GetNumberOfDays()[2] << '\n';
	cout << degreeTypeStrings[this->GetDegreeProgram()] << '\n';


}

Student::~Student()
{
}


