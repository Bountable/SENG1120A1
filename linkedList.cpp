
/*
// linkedList.cpp
// -----------------------------------------------
// Provides the functionality and operations 
// required for a linked list
// 
// -----------------------------------------------
// Written by SENG1120 Student: Darcy Studdert c3404758
// 4-09-2022
// Last update: 4/09/22 4:49pm
// -----------------------------------------------


			   |--HEAD--|      |-------------|      |-----TAIL----|
	           | next --|----->| next -------|----->| next -------|--->NULL
	   NULL<---|-prev   |<-----|-prev        |<-----|-prev        |
	           | val    |      | val         |      | val         |
	           |--------|      |-------------|      |-------------|  

*/

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
LinkedList::~LinkedList()
{
	current = head;
	for(start(); current!=NULL; forward()) 
    {
        remove_from_current();
        current++;
    }

}

//DATA IN AND DATA OUT

//preCondition: n/a
//postCondition: new node carrying the data will be slotted at the head of the list. The head will be replaced to the current node.  
 void LinkedList::add_to_head(const value_type& item){
 	if(current != NULL){
 		Node* newNode = new Node(item); //create new Node
 		head->setPrev(newNode);
 		newNode->setNext(head);
 		newNode->setPrev(NULL);
 		head = newNode;
 		current = head;
 		size_++;
 	}
 	else
	{
		Node* newNode = new Node(item); 
	    newNode->setPrev(NULL);
	    newNode->setNext(NULL); 
	    tail = newNode; 
	    head = newNode; 
	    current = head; 
	    size_++; 


 	}


 }

 //preCondition: n/a
 //postCondition: a node will be added to the tail of the list. 
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
 	else
 	{
 		Node* newNode = new Node(item); 
	    newNode->setPrev(NULL); 
	    newNode->setNext(NULL);
	    tail = newNode; 
	    head = newNode; 
	    current = head; 
	    size_++; 
 	}


 }

//preCondition: n/a
//postCondition: a node will be slotted at the current pointer position. 
void LinkedList::add_current(const value_type& item){

	//checks if List is NOT empty
	if(current != NULL)
	{

		Node* newNode = new Node(item); //create new Node
		newNode->setNext(current); //sets next of newnode to the current
		newNode->setPrev(current->getPrev()); //sets previouse of newnode the current pointer nodes previouse
		current->setPrev(newNode); // points the prev of current to newNode
		newNode->getPrev()->setNext(newNode); //sets the next of new previouse node to newNode

		current = head;
		size_++;

	}
	else //if linked list is empty
	{
		Node* newNode = new Node(item); //create new Node 
	    newNode->setPrev(NULL); //set previouse of new node to null
	    newNode->setNext(NULL); //set next of new ndoe to null
	    tail = newNode; //sets tail of LL
	    head = newNode; //sets Head of LL
	    current = head;  //sets current to the head
	    size_++;  //increase size of LL
	}
	
}

//preCondition: n/a
//postCondition: the node at the head will be deleted. size_ of LL will be one less
void LinkedList::remove_from_head(){
	Node* temp; //temp pointer to Node
	temp = head; //set the temp to the head
	head = head->getNext(); //gets next of pointer

	//if list is not empty
	if(head != NULL)
	{
		head->setPrev(NULL);
	}

	else //list is empty update tail
	{
		tail = NULL;
	}

	delete temp; //deletes node
	size_ --;
}


//preCondition: n/a
//postCondition: the node at the tail will be deleted. size_ of LL will be one less
void LinkedList::remove_from_tail()
{
    Node* tempNewNode = current->getPrev(); // set temp node pointer to prev of current
    tempNewNode->setNext(NULL); // set next of temp node to NULL
    delete current; // remove the current node
    tail = tempNewNode; // set tail to the temp node
    start(); // set current to head
    size_--; // decrease length counter of the list by 1
}

//preCondition: n/a
//postCondition: node at the current position will be removed. size_ will be one less
void LinkedList::remove_from_current(){
	current->getPrev()->setNext(current->getNext()); //set the next  of the node before to point to the node after 
	current->getNext()->setPrev(current->getPrev()); // sets the prev of the node ahead to point to the node before
	delete current; //delete node
	current = head; 
	size_--;
}

//preCondition: LL is not empty
//postCondition: the node with the value that matches string name will be removed. size_ will be one less
void LinkedList::remove(const string name){

	for(start(); current !=NULL; forward()) //loop through LL
	{
		if(name == get_current().get_name()) //if name matches
		{
			if(current->getPrev()==NULL && current->getNext()==NULL) //if LL is size one
			{
				delete current;
				size_--;

			}
			else if(current->getPrev()==NULL && current->getNext()!=NULL) //iff match is found at the head
			{
				remove_from_head();
			}
			else if (current->getNext()==NULL && current->getPrev()!= NULL) //if match is found at the tail
			{
				remove_from_tail();
			}
			else
			{
				remove_from_current(); //if match is found anywhere else
			}

		}

	}
	
}


//ACCESSOR METHODS

//preCondition: Linkedlist must not be empty
//postCondition: will return the data found at the current position
Node::value_type LinkedList::get_current() const{
	return current->getData();

}

//preCondition: Linkedlist must not be empty
//postCondition: will return the data found at the tail of the LL
Node::value_type LinkedList::getFromTail() const{
	return tail->getData();

}

//preCondition: Linkedlist must not be empty
//postCondition: will return the data found at the head of the LL
Node::value_type LinkedList::getFromHead() const{
	return head->getData();
}

//preCondition: LinkedList must not be empty
//postCondition: moves current to the head
void LinkedList::start() 
{
	current = head;

}

//preCondition: LinkedList must not be empty
//postCondition: moves current to the tail
void LinkedList::end() 
{
	current = tail;

}

//preCondition: LinkedList must not be empty
//postCondition: moves current to the next node
void LinkedList::forward() 
{
	current = current->getNext();
}

//preCondition: LinkedList must not be empty
//postCondition: moves current previouse node
void LinkedList::back() 
{
	current = current->getPrev();
}

//preCondition: n/a
//postCondition: returns the size of the linkedlist
int LinkedList::getSize()
{
	return size_;
}


//preCondition: LinkedList must not be empty
//postCondition: averages the score() of the LinkedList
const double LinkedList::calcAverage(){

 	double average;
    double total = 0;
    int counter = 0;
    for(start(); current!=NULL; forward())  //loop through LL until end
    {   
        total += get_current().get_score();  //adds score of the current node
        counter++; 
    }
    average = (total/counter); //average formula
    return average;
}


//preCondition: n/a
//postCondition: counts how many times the name matches the parametres
const int LinkedList::Count(const string name){

  	int counter = 0;
    for(start(); current!=NULL; forward()) //loop through LL until end
    {   
        
        if(name==get_current().get_name()) //name is match
        {
        	counter++;
        }
    }
    return counter;

}



//OPERATOR OVERLOADING

//preCondition: n/a
//postCondition: returns all the data found withthin the linkedLists 
ostream& operator << (ostream& out, LinkedList& LinkedList)
{
    LinkedList.start(); 
   
    for(int i=0;i<LinkedList.getSize();i++) //loop through linked list 
    {
        out << LinkedList.get_current(); //prints data
        LinkedList.forward(); 
    }
    LinkedList.start();
    return out;
}

//preCondition: n/a
//postCondition: concatonates two linked lists
LinkedList& operator += (LinkedList& LinkedListOne, LinkedList& LinkedListTwo)
{
    LinkedListOne.start();
    LinkedListTwo.start(); 

    for(int i=0; i<LinkedListTwo.getSize(); i++) //loopts through second linked list
    {
        LinkedListOne.add_to_tail(LinkedListTwo.get_current()); //concatonate the current of LL2 to the tail of LL1
        LinkedListTwo.forward(); 
    }
    LinkedListTwo.start(); 
    LinkedListOne.start();
    return LinkedListOne;
}