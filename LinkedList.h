// LinkedList.h
// -----------------------------------------------
// header for linkedlist.cpp
// 
// 
// -----------------------------------------------
// Written by SENG1120 Student: Darcy Studdert c3404758
// 4-09-2022
// Last update: 4/09/22 4:49pmm
// -----------------------------------------------



//macroguards
#ifndef linkedlist_Darcy
#define linkedlist_Darcy


#include <string>
#include <cstdlib>
#include <iostream>
#include "Node.h"
using namespace std;


class LinkedList
{


    
public:
    typedef Node::value_type value_type;

    LinkedList(); //constructor
    ~LinkedList(); //destructor


    //Data In and Data Out
    void add_to_head(const value_type& item);//creates node with value item which is then slotted into the head of the LL

    void add_to_tail(const value_type& item);//Creates a node with value item which is then slotted to the tail of the LL

    void add_current(const value_type& item); //Creates a Node with value item which is then slotted at wherever current is

    void remove_from_head(); //deletes the node at the head

    void remove_from_tail(); //deletes the node at the tail

    void remove_from_current();//deletes node wherever the current is

    void remove(const string name); //will remove nodes with the string name matches

  


    //Current Pointer Manipulation
    void start(); // moves current to the head

    void end(); // moves current to the tail

    void forward(); // moves current one node to the right

    void back(); // moves current one node to the left

    Node::value_type get_current() const; //gets the node values from current position

    Node::value_type getFromTail() const; //gets the node values from the tail

    Node::value_type getFromHead() const; //gets the node values from the head

    int getSize(); //gets the size of the LL

    const double calcAverage(); //calculates the average of the LL

    const int Count(const string name); //counts the the amount of matching names





private:

    Node*  head;
    Node*  tail;
    Node*  current;
    int  size_;
};

ostream& operator << (ostream& out, LinkedList& Linkedlist);    //overloades the << operator to return LL values
LinkedList& operator += (LinkedList& LinkedListOne, LinkedList& LinkedListTwo); //overloades the += to concatonate 2 linkes lists


#endif
//macroguard