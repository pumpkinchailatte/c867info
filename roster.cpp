#include <iostream>
#include <string>	
#include <fstream>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;
#include <array>
#include <string>
//includes member function defintions

//functions;
/*a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.

b.  public void remove(string studentID)  that removes students from the roster by student ID.If the student ID does not exist, the function prints an error message indicating that the student was not found.

c. public void printAll() that prints a complete tab - separated list of student data in the provided format : A1[tab] First Name : John[tab] Last Name : Smith[tab] Age : 20[tab]daysInCourse : {35, 40, 55} Degree Program : Security.The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.

d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses.The student is identified by the studentID parameter.

e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user. */
Roster::Roster() {

}


//not completed:: wtf
void Roster::parse(string studentData) {

	//find info for each obj in roster ? probs will be lengthy? yeah i have absolutely no idea
	//get attributes for each studentobject
	//Roster* obj = new Roster;

	DegreeProgram degree = SECURITY; //default value
	if (studentData.back() == 'K') degree = NETWORK; //checks the back character of degreeProgram to identify which program a student is in
	else if (studentData.back() == 'E') degree= SOFTWARE; // checks the back character of degreeProgram to identify which program a student is in

	size_t rhs = studentData.find(",");
	string id = studentData.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string fname = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lname = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string email = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));
	/*
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string strDegree = (studentData.substr(lhs, rhs - lhs));
	
	DegreeProgram degree = DegreeProgram::SOFTWARE;

	if (strDegree == "SOFTWARE") {
		degree = SOFTWARE;
	}
	else if (strDegree == "NETWORK") {
		degree = DegreeProgram::NETWORK;
	}
	else if (strDegree == "SECURITY") {
		degree = DegreeProgram::SECURITY;
	}*/
	Roster::add(id, fname, lname, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
	//leave return or nah? return on a new line maybe?
	return;
}

void Roster::add(string id, string fname, string lname, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree)
{//everything in my function would release after return 0? so no need to clean out? but needs to be "saved" somewhere..into an object? is it inside an array? maybe theres no array? classrosterarray will hold pointers for location of only my course days?
	//add all? or just my new info?
	// ]for (int i = 0; i < 5; i++)?
	// //for each array entry there are multiple attributes separated by ,
	//transformation 
	int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	//student();

	classRosterArray[++Lastindex] = new student(id, fname, lname, email, age, days, degree); // O_O
		//add all student objects into the classRosterArray
	return;
}


//completed: no idea if works 
void Roster::printAll() { //print all? idk if this has anythin correct at all, wouldnt we just use student constructor somewhere? i dont think we use classrosterarray... where are we putting the objects?
	for (int i = 0; i < 5; i++) {
		cout << classRosterArray[i]->GetId() << '\t';
		cout << classRosterArray[i]->GetFname() << '\t';
		cout << classRosterArray[i]->GetLname() << '\t';
		cout << classRosterArray[i]->GetEmail() << '\t';
		cout << classRosterArray[i]->GetAge() << '\t';
		cout << classRosterArray[i]->Getdays() << '\t';
		cout << endl;
	};
}

void Roster::printAvgDays(string id) {
	int avgDays = 0;
	for (int i = 0; i < Roster::numStudent; i++) {
		avgDays = (classRosterArray[i]->Getdays()[0] + classRosterArray[i]->Getdays()[1] + classRosterArray[i]->Getdays()[2]) / 3;
		cout << "Student ID: " << id << "," << " average days in course is: " << avgDays << endl;

	};
}

void Roster::removeId(string id) {//rework this. i dont think this works at all honestly.
	int contin = 1;
	for (int i = 0; i < Roster::numStudent; i++) {
		if (id == classRosterArray[i]->GetId()) { //find match
			delete classRosterArray[i]; //can we even do this? arent arrays set size? do we clear it out?
			contin = 0;
		}
		else {
			continue;
		}
	}

	//after looping checking for id and deleting, either continue or print error
	if (contin == 1) {
		cout << "The student with the ID: " << id << " was not found." << endl;
	}
}
	
void Roster::printInvalidEmail() {
	for (int i = 0; i < Roster::numStudent; i++) {
		string email = (classRosterArray[i]->GetEmail());
		if ((email.find(" ")) or (email.find("_"))) {
			cout << email << " - is invalid" << endl;
		}
		else {
			continue;//idk if this is correct so check this
		}
	}

}
void Roster::printByDegree(DegreeProgram degree) { //mayve add degreestring into this? ?? IDK I LITERALY DO NOT KNOW
	for (int i = 0; i < Roster::numStudent; i++) {
		DegreeProgram theDegree = classRosterArray[i]->GetDegree();
		if (theDegree == SOFTWARE) {
			classRosterArray[i]->print();
			cout << endl;
		}
		else {
			continue;
		}
	}
};

Roster::~Roster() {
	for (int i = 0; i < 5; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	};
} //destructor?
