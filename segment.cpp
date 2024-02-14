// Bryce Diedrich
// CS163 Program #2
// Feb 2 2024
//
// This file provides the implementation of the Stack and
// Segment class methods.
//
// The public methods of Stack implemented below are:
// - push:    takes a Segment object by refrence as input and
//            places it on the top of the stack
// - pop:     takes a Segment object by reference as input and
//            removes a Segment object from the top of the stack,
//            and copies it to the passed record object.j
// - peek:    takes no input. prints the data values of the segment
//            at the top of the stack.
// - display: takes no input. prints the data values of all segments
//            on the stack.
//
// The public methos of Record implemented below are:
// - createSegment: takes three char * objects for the transit type, and
//                  the start and end location names, and one bool to indicate
//                  if the segment runs on the weekends. these values are then 
//                  copied into the private data members of the calling Record object.
// - copyRecord:    takes a Segment object by reference as input and copies 
//                  it's data member values to the data members of the calling
//                  Segment object.
// - display:       takes no input. displays the data member values of the 
//                  calling Segment object.

#include "stack.h"
#include <ostream>
#include <iostream>
#include <cstring>

using namespace std;

// constructor. initializes the head pointer to NULL and sets the stack index to 0
Stack::Stack()
{
    head = nullptr;
    top_index = 0;
}

// destructor. frees all memory allocated by stack objects
Stack::~Stack()
{
/*
    SegmentNode * inc = head;
    SegmentNode * next_node;

    // outer while loop traverses the LLL 
    while(!(inc == nullptr))
    {
        delete[] inc->segments;
        next_node = inc->next;
        delete inc;
        inc = next_node;
    }
*/

    releaseStack(head);
}

// takes Segment object by reference and pushes it onto the top of the stack
int Stack::push(Segment & to_push)
{
    // if the current node's array is full
    // or there are no nodes initialized on
    // the stack, we handle that the same
    if(top_index == MAX || head == nullptr)
    {
        // allocate a Segment node, place it at the front of the list,
        // and allocate an array of Segments of size MAX.
        SegmentNode * tmp = new SegmentNode;
        tmp->next = head;
        head = tmp;
        head->segments = new Segment[MAX];
        top_index = 0;

        // copy the passed segments data to the segment at the 
        // top of the stack,
        head->segments[top_index].copySegment(to_push);
        ++top_index;
    }
    // if the current node's array is ot full
    // and we have at least one node in the 
    // list, then we simply copy the passed 
    // segment to the next available element
    // on our current array.
    else
    {
        head->segments[top_index].copySegment(to_push);
        ++top_index;
    }

    return 0;
}

// removes segment object from the top of the stack and copies it to
// the passed by referece segment object
int Stack::pop(Segment & pop_to)
{
    // if the current node's array is empty we will have to pop
    // from the next node if it exists.
    if(top_index == 0)
    {
        // if there is no next node, return error indicating there are  
        // no segments to pop
        if(head->next == nullptr)
            return 1; 
        
        // point temporary deleter node to the head of the list
        // and increment head to the next node
        SegmentNode * deleter = head;
        head = head->next;
        
        // set index to top of the next node and copy the segment
        // at that element
        top_index = MAX-1;
        pop_to.copySegment(head->segments[top_index]);
        
        // free our segment array and node that was empty
        delete[] deleter->segments;
        delete deleter;
    }
    // if the current node's array is not empty, then we can
    // decrement the index to pop it from the stack and then
    // copy it's data to the passed by reference segment
    else
    {
        --top_index;
        pop_to.copySegment(head->segments[top_index]);
    }

    return 0;
}

//
int Stack::peek()
{

    if(head == nullptr)
        return 1; //error: nothing left to pop

    if(head->next == nullptr && top_index == 0)
        return 1; //error: nothing left to pop

    cout << "\e[1mSegment object at the top of the stack:" << "\e[0m" << endl;
    head->segments[top_index-1].display();

    return 0;
}

int Stack::display()
{
    SegmentNode * inc = head;
    char answer[5];
    int tmp_index = top_index - 1;

    if(head == nullptr)
        return 1; //error: nothing left to pop
    if(head->next == nullptr && top_index == 0)
        return 1; //error, nothing on stack to display

    cout << endl;
    // outer while loop traverses the LLL 
    while(!(inc == nullptr))
    {
        // inner fo
        for(tmp_index; tmp_index >= 0; --tmp_index)
        {
            cout << "\e[1mStack Object at Index " << tmp_index << "\e[1m" << endl;
            inc->segments[tmp_index].display();
        }
        tmp_index = MAX-1;
        inc = inc->next;
    }
    cout << endl;
    
    return 0;
}

int Stack::releaseStack(SegmentNode * head)
{
    SegmentNode * placeholder;

    if(head == nullptr)
        return 0;

    placeholder = head->next;
    
    delete[] head->segments;
    delete head;

    releaseStack(placeholder);

    return 0;
}

Segment::Segment()
{
    char * transit_type = nullptr;
    char * location_start = nullptr;
    char * location_end = nullptr;
    bool runs_on_weekends = false;
}

Segment::~Segment()
{
    if(transit_type != nullptr)
    {
        cout << "deleting " << transit_type << endl;
        delete[] transit_type;
    }

    if(location_start != nullptr)
    {
        cout << "deleting " << location_start << endl;
        delete[] location_start;
    }
    
    if(location_end != nullptr)
    {
        cout << "deleting " << location_end << endl;
        delete[] location_end;
    }
}

int Segment::createSegment(char * transit_type, char * location_start, char * location_end, bool runs_on_weekends)
{
    int result = copyString(transit_type, this->transit_type);
    if(result != 0)
        return result;

    result = copyString(location_start, this->location_start);
    if(result != 0)
        return result;

    result = copyString(location_end, this->location_end);
    if(result != 0)
        return result;

    this->runs_on_weekends = runs_on_weekends;

    return 0;
}

int Segment::copySegment(Segment & copy_from)
{
    int result = copyString(copy_from.transit_type, this->transit_type);
    if(result != 0)
        return result;

    result = copyString(copy_from.location_start, this->location_start);
    if(result != 0)
        return result;

    result = copyString(copy_from.location_end, this->location_end);
    if(result != 0)
        return result;

    this->runs_on_weekends = copy_from.runs_on_weekends;
    
    return 0;
}

int Segment::display()
{
    cout << "    Transit Type: " << transit_type << endl
         << "    Staring Location: " << location_start << endl
         << "    Ending Location: " << location_end << endl
         << "    Runs on weekends?: " << runs_on_weekends<< endl;

    return 0;
}

int Segment::copyString(char * copy_from, char * &copy_to)
{
    // if copy_from is a null pointer or if it points to an empty string then we return
    // error and exit function
    if(!copy_from || (*copy_from)=='\0')
        return 1; // return 1 for error

    // stores size of copy_from's array
    int size = strlen(copy_from); 
    // allocates array on heap of size of copy_from's array
    copy_to = new char[size+1];
    // steps through array copying each character from copy_from to copy_to
    for(int inc=0;inc<size;inc++)
    {
        copy_to[inc] = copy_from[inc]; 
    }

    // adds terminating character to end of copy_to
    copy_to[size] = '\0';

    return 0;
}


