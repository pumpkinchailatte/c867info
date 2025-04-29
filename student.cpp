#include <iostream>
#include <string>
#include <fstream>
#include "student.h"
using namespace std;

student::student() {
	this->id = "";
	this->fname = "";
	this->lname = "";
	this->email = "";
	this->age = 0;
	this->days[0] = 0;
	this->days[1] = 0;
	this->days[2] = 0;//she said to put just 0 
	this->degree = DegreeProgram::SOFTWARE;
}

student::student(string id, string fname, string lname, string email, int age, int days[], DegreeProgram degree) {
	this->id = id;
	this->fname = fname;
	this->lname = lname;
	this->email = email;
	this->age = age;
	this->days[0] = days[0];
	this->days[1] = days[1];
	this->days[2] = days[2];
	this->degree = degree;
}

//accessors
string student::GetId() { return this->id; }
string student::GetFname() { return this->fname; }
string student::GetLname() { return this->lname; }
string student::GetEmail() { return this->email; }
int student::GetAge() { return this->age; }
int* student::Getdays() { return this->days; } //why wont work 
DegreeProgram student::GetDegree() { return this->degree; }

/*student class: needs to include (student id, first name, last name
, email age, array of numbers of daays to complete course, degree

contains memeber function definitions, can create empty functions for now*/

//mutators: do these need to be pointers?? this-> or nah? idkkkkkk
void student::setID(string id) { this->id = id;}
void student::setFname(string fname) { this->fname = fname;}
void student::setLname(string lname) { this->lname = lname; }
void student::setEmail(string email) { this->email = email; }
void student::setAge(int age) { this->age = age; }
void student::setdays(int days[]) {
	for (int i = 0; i < 3; i++) {
		this->days[i] = days[i];
	}
}
void student::setDegree(DegreeProgram degree) { this->degree = degree; }


void student::print() {
	cout << this->GetId() << "/t";
	cout << this->GetFname() << "/t";
	cout << this->GetLname() << "/t";
	cout << this->GetEmail() << "/t";
	cout << this->GetAge() << "/t";
	cout << this->Getdays()[0] << ",";
	cout << this->Getdays()[1] << ","; 
	cout << this->Getdays()[2] << ","; // do we need to specify each day individual?
	cout << this->GetDegree() << endl; //i think i need to specify degree string somehowehr and how
	return;
} 


//deconstructor? what do i put in here?
student::~student() {}

