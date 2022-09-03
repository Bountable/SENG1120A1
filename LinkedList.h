// This defines a class that represents an
// account object for double numbers of a currency.
// Programmer: Alex Mendes
// Last modified:  14 Dec 2017
// This file should be used in conjunction with Lab 1 for SENG1120
#ifndef linkedlist_H
#define linkedliSt_H


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
    void add_to_head(const value_type& item);//DONE

    void add_to_tail(const value_type& item);//DONE

    void add_current(const value_type& item); //DONE

    void remove_from_head(); //DONE

    void remove_from_tail(); 

    void remove_from_current();//DONE

    Node::value_type getFromTail() const;

    Node::value_type getFromHead() const;


    //Current Pointer Manipulation
    void start(); // moves current to the head

    void end(); // moves current to the tail

    void forward(); // moves current one node to the right

    void back(); // moves current one node to the left

    Node::value_type get_current() const;

    int size();




private:

    Node*  head;
    Node*  tail;
    Node*  current;
    int  size_;
};


#endif