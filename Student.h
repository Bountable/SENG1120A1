// Student.h
// -----------------------------------------------
// A simple Student object, that holds nothing 
// more than a String Name and an Integer Grade;
// includes a basic stream insertion function.
// -----------------------------------------------
// Written by SENG1120 Staff: 2009-05-01
// Last update: 2022-08-03
// -----------------------------------------------

#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class Student 
{
public:
	
	// Constructors
	Student();
	Student(const string, const int);

	// Destructor
    ~Student();

	// Setters
    void set_name(const string);
	void set_score(const int);

	// Getters
	string get_name() const;
	int get_score() const;

//Private member variables
private:
	string name; // student's name
	int score;	// student's score
};

ostream& operator <<(ostream&, const Student&);

#endif