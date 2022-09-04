#ifndef NODE_DARCY
#define NODE_DARCY
#include <cstdlib>
#include "Student.h"

// Node.h
// -----------------------------------------------
// head for node.cpp
// 
// 
// -----------------------------------------------
// Written by SENG1120 Student: Darcy Studdert c3404758
// 4-09-2022
// Last update: 4/09/22 4:49pm
// -----------------------------------------------

using namespace std; 

class Node 
{
	public:
		typedef Student value_type;

		// constructors
		// specific constructor 
		Node(const value_type& data1); // ths will se the  data with a null next and prev pointers
		
		// destructor
		~Node();

		// setters
		void setPrev(Node* prev); // sets prev pointer 
		void setNext(Node* next); // sets next pointer 
		void setData(const value_type& i); // sets data of the node

		// getters
		Node* getPrev() const; // gets prev pointer 
		Node* getNext() const; // gets next pointer 
		value_type getData() const; // gets data from node

	// private member variables
	private:
		// stores data
		value_type data; // data of a node

		// node pointers
		Node* prev; // pointer to prev 
		Node* next; // pointer to next 
};
#endif