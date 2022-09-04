#include <iostream>
#include "Node.h"

// node.cpp
// -----------------------------------------------
// provides functionality and operations
// required ofor a Node
// 
// -----------------------------------------------
// Written by SENG1120 Student: Darcy Studdert c3404758
// 4-09-2022
// Last update: 4/09/22 4:49pm
// -----------------------------------------------

typedef Student value_type;

//Constructor
Node::Node(const value_type& data1){
	data = data1; 
	prev = NULL;
	next = NULL;
}

//Destructor
Node::~Node(){

}

//SETTERS
void Node::setPrev(Node* prev_ptr){
	prev = prev_ptr; //set prev pointer
}

void Node::setNext(Node* next_ptr){
	next = next_ptr; //set next pointer
}


// GETTERs
Node* Node::getNext() const{
	return next; //get next
}

Node* Node::getPrev() const{
	return	prev; //get prev
}



void Node::setData(const value_type &i)
{
	data = i;
} // sets data of the node


Node::value_type Node::getData() const
{
	return data;
} // gets data from node