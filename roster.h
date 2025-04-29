#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "student.h"
using namespace std;
#ifndef ROSTER_H
#define ROSTER_H

//class definition, --including data members and memeber function declarations

class Roster {  //hold data from studentData table //number of students in array?
private:
public: //create an object for each student + populate array
	Roster();
	//Roster(studentData);
	~Roster(); //de structor to clean up? here? or where?

	const static int numStudent = 5;
	student* classRosterArray[numStudent]; //pointer?-> *, new array?, number of studentnumber
	int Lastindex = -1;

	void parse(string studentData); // parse each set of data identified in the table, extract all attributse from string
	void add(string id, string fname, string lname, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree); //add all idk wwhere?? dont know where. 
	void removeId(string id); //to remove particular id
	void printAll(); //print everything left over after removing particular id
	void printAvgDays(string id); //print average days
	void printInvalidEmail(); //print all invalid emails
	void printByDegree(DegreeProgram degree); //print all objects with certain attribute degree:software




	//void setValue(int index, int* value); //function to set value at specific index
	//classRosterArray* getValue(int index) const; //function to get value at specific index


};
//array of pointers called classRosterArray to hold data


/* umm idk where to add this to so idk
void student::printByDegree() //idk where to put this , nowhere seems right
{
	string degree_string;
	if (student::degree == SOFTWARE) {
		degree_string = "SOFTWARE";
	}
	else if (student::degree == NETWORK) {
		degree_string = "NETWORK";
	}
	else if (student::degree == SECURITY) {
		degree_string = "SECURITY";
	}
	cout << id << "\t" << fname << "\t" << lname << "\t" << email << "\t" << age << "\t" << days[3] << "\t" << degree_string << endl;
	return;
}
*/


#endif
