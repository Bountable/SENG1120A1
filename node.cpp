#include <iostream>
#include "Node.h"

typedef Student value_type;

//Node::Node(){} TODO

Node::Node(const value_type& data1){
	data = data1; 
	prev = NULL;
	next = NULL;
}

Node::~Node(){

}

//SETTERS
void Node::setPrev(Node* prev_ptr){
	prev = prev_ptr;
}

void Node::setNext(Node* next_ptr){
	next = next_ptr;
}


// GETTERs
Node* Node::getNext() const{
	return next;
}

Node* Node::getPrev() const{
	return	prev;
}
