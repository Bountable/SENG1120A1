// LinkedListDemo.cpp
// -------------------------------------------------
// This program demonstrates the basic functionality 
// of a linked list that stores student names and 
// scores. It will demo the functions of a basic 
// linked list. The program adds content to a 
// linked list, removes individual nodes, among 
// other functionalities.
// -------------------------------------------------
// Written by SENG1120 Staff: 2009-05-01
// Last update: 2022-08-03 (for sem 2)
// -------------------------------------------------


#include <iostream>
#include <cstdlib>
#include "Linkedlist.h"
#include "Student-1.h"
using namespace std;

void initialize(LinkedList &l1, LinkedList &l2)
{
	// populate the first linked list
    Student c("Alex", 15);
    l1.add_to_tail(c);
    c.set_name("Peter"); c.set_score(10);
    l1.add_to_tail(c);
	c.set_name("John"); c.set_score(32);
    l1.add_to_tail(c);
    c.set_name("Mary"); c.set_score(50);
    l1.add_to_tail(c);
	c.set_name("Carol"); c.set_score(31);
    l1.add_to_tail(c);

    // and populate the second
	c.set_name("Tony"); c.set_score(60);
    l2.add_to_head(c);
    c.set_name("John"); c.set_score(75);
    l2.add_to_head(c);
    c.set_name("Michelle"); c.set_score(90);
    l2.add_to_head(c);
    c.set_name("Tim"); c.set_score(20);
    l2.add_to_head(c);
    c.set_name("Carol"); c.set_score(27);
    l2.add_to_head(c);
    c.set_name("Michelle"); c.set_score(12);
    l2.add_to_head(c);
}

int main()
{
	// create two LinkedLists
    LinkedList firstList;
	LinkedList secondList;
	// the List container will be on the stack, however the Nodes will
	// be on the heap!
	
	// add data
	initialize(firstList, secondList);

	// initial state
	cout << "Start lists:" << endl;
	cout << "List 1: " << firstList  <<  endl;				// LinkedList needs operator <<
	cout << "List 2: " << secondList <<  endl << endl;

	// concatenate
	cout << "Concatenating the two lists onto list '1':" << endl;
	firstList += secondList;								// LinkedList needs operator +=
    cout << "List 1: " << firstList  << endl;
	cout << "List 2: " << secondList << endl << endl;

	// removals
	cout << "Removing student 'Alex' from list '1':" << endl;
    firstList.remove("Alex");
    cout << "List 1: " << firstList  << endl;
	cout << "List 2: " << secondList << endl << endl;

	cout << "Removing student 'John' from list '2':" << endl;
    secondList.remove("John");
    cout << "List 1: " << firstList  << endl;
	cout << "List 2: " << secondList << endl << endl;

	cout << "Removing student 'Michelle' from both lists:" << endl;
    firstList.remove("Michelle");
    secondList.remove("Michelle");
    cout << "List 1: " << firstList  << endl;
	cout << "List 2: " << secondList << endl << endl;

	cout << "Removing student 'Fred' from list '2':" << endl;
    secondList.remove("Fred");
    cout << "List 1: " << firstList  << endl;
	cout << "List 2: " << secondList << endl << endl;
	
	// get an average
	cout << "Average of list '1': ";
	cout << firstList.calcAverage() << endl;
	
	cout << "Average of list '2': ";
	cout << secondList.calcAverage() << endl << endl;

	// count names
	cout << "Number of students named 'Carol': ";
	cout << (firstList.count("Carol") + secondList.count("Carol")) << endl << endl;

//  Uncomment this section if you are implementing the function order()	
//	cout << "Ordered lists: " << endl;
//	firstList.order();
//	secondList.order();
//	cout << "List 1: " << firstList  << endl;
//	cout << "List 2: " << secondList << endl << endl;

	// Done
	cout << "The program has finished." << endl;
	return 0;
}
