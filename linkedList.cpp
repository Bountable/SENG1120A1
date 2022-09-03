#include <iostream>
#include "LinkedList.h"
#include "Node.h"


//specific constructor
LinkedList::LinkedList(){
	head = NULL;
	tail = NULL;
	current = NULL;
	size_ = 0;

}

//Destructor
LinkedList::~LinkedList(){}




 void LinkedList::add_to_tail(const value_type& item){

 	if(current != NULL)
 	{
 		Node* newNode = new Node(item); //create new Node
 		tail->setNext(newNode);
 		newNode->setPrev(tail);
 		newNode->setNext(NULL);
 		tail = newNode;
 		current = head;
 		size_++;

 	}


 }


void LinkedList::add_current(const value_type& item){

	//checks if List is NOT empty
	if(current != NULL)
	{
		Node* newNode = new Node(item); //create new Node
		newNode->setNext(current); //sets nextof newnode to the current
		newNode->setPrev(current->getPrev()); //sets previouse of newnode the current pointer nodes previouse
		current->setPrev(newNode); // points the prev of current to newNode
		newNode->getPrev()->setNext(newNode); //sets the next of new previouse node to newNode

		current = head;
		size_++;

	}
	
}

