#pragma once
#include <string>
#include<iostream>
#include "degree.h"
#include "student.h"
#include "roster.h"






using namespace std;


Roster::Roster()
{
	
}

void Roster::ParseAdd(string studentData)
{
	
		DegreeProgram degreeProgram = SOFTWARE;

		if (studentData.back() == 'Y' )degreeProgram =SECURITY;
		else if (studentData.back() == 'K')degreeProgram = NETWORK;
		else if (studentData.back()== 'E')degreeProgram = SOFTWARE;

		else
		{
		cout << "INVALID Degree Type !  Exiting now!\n";
		exit(-1);
		}
		//studentId

		int rhs = studentData.find(",");

		string studentID = studentData.substr(0, rhs);

		//read firstName

		int lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string firstName = studentData.substr(lhs, rhs - lhs);

		//readlastname

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string lastName = studentData.substr(lhs, rhs - lhs);

		//read emailAddress

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string emailAddress = studentData.substr(lhs, rhs - lhs);

		//read age


		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int age = stoi(studentData.substr(lhs, rhs - lhs));
		//lhs = rhs + 1;
		//rhs = studentData.find(",", lhs);



		//read days of study

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

		add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);


	}



	void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
	{
		int numberOfdays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

		ClassRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, numberOfdays, degreeProgram);

	}

	void Roster::remove(string studentID)
	{
		bool found = false;
		for (int i = 0; i <= lastIndex; i++)
		{
			if (ClassRosterArray[i]->GetStudentID() == studentID)
			{
				found = true;
				

				delete this->ClassRosterArray[i];
				this->ClassRosterArray[i] = this->ClassRosterArray[lastIndex];
				lastIndex--;
			}
			if (!found)
			{
				cout << "Student: " <<studentID<<" has been removed" << endl;
			}

			
		}
		cout << "\n";
	}


	void Roster::printAll()
	{
		for (int i = 0; i <= Roster::lastIndex; i++)
		{
			cout << ClassRosterArray[i]->GetStudentID(); cout << '\t';
			cout << ClassRosterArray[i]->GetFirstName(); cout << '\t';
			cout << ClassRosterArray[i]->GetLastName(); cout << '\t';
			cout << ClassRosterArray[i]->GetEmailAddress(); cout << '\t';
			cout << ClassRosterArray[i]->GetAge(); cout << '\t';
			cout << ClassRosterArray[i]->GetNumberOfDays()[0]; cout << '\t';
			cout << ClassRosterArray[i]->GetNumberOfDays()[1]; cout << '\t';
			cout << ClassRosterArray[i]->GetNumberOfDays()[2]; cout << '\t';
			cout << degreeTypeStrings[ClassRosterArray[i]->GetDegreeProgram()] << endl;
			
		}cout << "\n";
	}

	void Roster::printAverageDaysInCourse(string studentID)
	{

		cout << "Average Days For Study: " << endl;
		
		for (int i = 0; i <= lastIndex; i++)
		{
			cout << ClassRosterArray[i]->GetStudentID() << " :";
			cout << ClassRosterArray[i]->GetNumberOfDays()[0] +
				ClassRosterArray[i]->GetNumberOfDays()[1] +
				ClassRosterArray[i]->GetNumberOfDays()[2] / 3 << endl;
		}
		cout << "\n";
	}

	void Roster::printInvalidEmails()
	{
		cout << "Invalid E-mail Addresses:"<<endl;
		bool error = false;
		
		for (int i = 0; i <= Roster::lastIndex; i++)

		{
			string eml = (ClassRosterArray[i]->GetEmailAddress());
			if (eml.find('@') == string::npos || eml.find('.') ==string::npos || eml.find('  ') != string::npos)
			{
				error = true;
				
				cout << eml<<endl; 
			}
			
		}
		cout << "\n";
	{

}



}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	cout << "Students By degree: ";
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (ClassRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			cout <<endl;
			ClassRosterArray[i]->Print();
			
		}
			
		cout << "\t";
	}
	cout << "\n";
}

Roster::~Roster()
{
}
