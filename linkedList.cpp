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


void LinkedList::remove_from_tail()
{
    Node* tempNewNode = current->getPrev(); // set temp node pointer to prev of current
    tempNewNode->setNext(NULL); // set next of temp node to NULL
    delete current; // remove the current node
    tail = tempNewNode; // set tail to the temp node
    start(); // set current to head
    size_--; // decrease length counter of the list by 1
}


void LinkedList::remove_from_current(){
	current->getPrev()->setNext(current->getNext());
	current->getNext()->setPrev(current->getPrev());
	delete current;
	current = head;
	size_--;
}

void LinkedList::remove(const string name){
	for(start(); current !=NULL; forward())
	{
		if(name == get_current().get_name())
		{
			if(current->getPrev()==NULL && current->getNext()==NULL)
			{
				delete current;
				size_--;

			}
			else if(current->getPrev()==NULL && current->getNext()!=NULL)
			{
				remove_from_head();
			}
			else if (current->getNext()==NULL && current->getPrev()!= NULL)
			{
				remove_from_tail();
			}
			else
			{
				remove_from_current();
			}

		}

	}
	
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



const double LinkedList::calcAverage(){

 	double average;
    double total = 0;
    int counter = 0;
    for(start(); current!=NULL; forward())  // arguments of the for list (set current to head / complete until current == NULL / move up the list one node)
    {   
        total += get_current().get_score(); // add the score of the current node to total
        counter++; // increase counter total by 1
    }
    average = (total/counter); // caluclate the average of the list using the count of the list and the total score of the entire list
    return average;
}



const int LinkedList::Count(const string name){

  	int counter = 0; // set counter to 0
    for(start(); current!=NULL; forward()) // arguments of the for list (set current to head / complete until current == NULL / move up the list one node)
    {   
        // if the name of the current node matches the string inputted to the method increase the counter by 1
        if(name==get_current().get_name())
        {
        	counter++;
        }
    }
    return counter;

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

LinkedList& operator += (LinkedList& LinkedListOne, LinkedList& LinkedListTwo)
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