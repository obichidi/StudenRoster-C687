#include "degree.h"
#include "student.h"

#include<iostream>
#include<string>
#include "roster.h"

using namespace std;




int main() {

	cout << "Scripting and Programming- Applications- C867" << "\n";
	cout << "C++" << "\n";
	cout << "#001244323"<<"\n";
	cout << "Obiajulu Chidi"<<endl;

	

	int numStudents = 5;
	

	const string studentData[5] =
	{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Obiajulu,Chidi,ochidi1@wgu.edu,43,15,20,9,SOFTWARE"
	};


	Roster* roster = new Roster();
	cout << "parsing data and adding students:\n";

	for (int i = 0; i < numStudents; i++)
	{
		roster->ParseAdd(studentData[i]);


	}
	roster->printAll();

	roster->printAverageDaysInCourse("A1");
	roster->printInvalidEmails();
	
	
	roster->printByDegreeProgram(SOFTWARE);
	roster->remove("A2");
	roster->printAll();
	
	cout << "DONE.\n";
	
	return 0;
};

