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

//Data In and Data Out

//preCondition: none
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


 }


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

void LinkedList::remove_from_head(){
	Node* temp;
	temp = head;
	head = head->getNext();

	if(head != NULL){head->setPrev(NULL);}
	else{tail = NULL;}
	delete temp;
	size_ --;


}

void LinkedList::remove_from_current(){
	current->getPrev()->setNext(current->getNext());
	current->getNext()->setPrev(current->getPrev());
	delete current;
	current = head;
	size_--;
}

 void remove_from_tail(){
 	//TODO

 }


Node::value_type LinkedList::get_current() const{
	return current->getData();

}

Node::value_type LinkedList::getFromTail() const{
	return tail->getData();

}

Node::value_type LinkedList::getFromHead() const{
	return head->getData();
}

void LinkedList::start() // moves current to the head
{
	current = head;

}
void LinkedList::end() // moves current to the tail
{
	current = tail;

}

void LinkedList::forward() // moves current one node to the right
{
	current = current->getNext();
}

void LinkedList::back() // moves current one node to the left
{
	current = current->getPrev();
}

int LinkedList::getSize()
{
	return size_;
}

ostream& operator << (ostream& out, LinkedList& LinkedList)
{
    LinkedList.start(); // set list current to head
    // arguments of the for list (create int "i" and set its value to 0 / complete until "i" equals or is greater then the value returned by getLength() / increase "i" by 1)
    for(int i=0;i<LinkedList.getSize();i++) 
    {
        out << LinkedList.get_current(); // output the data of the current node
        LinkedList.forward(); // move to the next node in the list
    }
    LinkedList.start();
    return out;
}

LinkedList& operator += (LinkedList& LinkedListOne, LinkedList LinkedListTwo)
{
    LinkedListOne.start();
    LinkedListTwo.start(); 
    for(int i=0; i<LinkedListTwo.getSize(); i++)
    {
        LinkedListOne.add_to_tail(LinkedListTwo.get_current()); 
        LinkedListTwo.forward(); 
    }
    LinkedListTwo.start();
    LinkedListOne.start();
    return LinkedListOne;
}