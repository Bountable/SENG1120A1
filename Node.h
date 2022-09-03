#ifndef NODE_H
#define NODE_H

#include <cstdlib>
#include "Student-1.h"

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
		Node* prev; // pointer to prev (or default: NULL)
		Node* next; // pointer to next (or default: NULL)
};
#endif