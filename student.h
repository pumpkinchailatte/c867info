#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "degree.h"
#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

/*student class: needs to include (student id, first name, last name
, email age, array of numbers of daays to complete course, degree

includes class definitions, data members, member function declarations
*/
//create student classDEFINITION, DECLARATIONS opf functions
class student {
public:
	const static int daysInCourse = 3; //bruhhhhh why do it make me have dos ugh
private:
		string id;
		string fname;
		string lname;
		string email;
		int age;
		int days[daysInCourse];
		DegreeProgram degree;
public:
	//bruh do i have to do each individual??? or nahjhhhh idk what im doing
	// constructors:?
	student();
	student(string id, string fname, string lname, string email, int age, int days[], DegreeProgram degree);
	~student();


	//accessors
	string GetId();
	string GetFname();
	string GetLname();
	string GetEmail();
	int GetAge();
	int* Getdays();
	DegreeProgram GetDegree();
	
	//mutators:
	void setID(string Id);
	void setFname(string fname);
	void setLname(string lname);
	void setEmail(string email);
	void setAge(int Age);
	void setdays(int days[]);
	void setDegree(DegreeProgram studentDegree);

	void print();


};

#endif // STUDENT_H
	
	/*functions declarations*/

	//accessor (getter) for each instance variable from part D1

	//mutator (setter) or each instance variale from D1

	//all external access +changes must be done using accesssor and mutator

	//constructor using all of input parameteres provided in table

	//print() to print specific student data

