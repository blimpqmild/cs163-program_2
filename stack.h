// Bryce Diedrich
// CS163 Program #2
// Feb 2 2024
//
// This file provides the ADT for the transit trip segments. 
//
// Our Stack class and SegmentNode Struct provides the stack data structure
// which is implemented as a linear linked list of arrays of Segment objects.   
// The Stack class provides the basic interface of a stack with operations like
// pop, push, peek, etc via it's public interface. It's private data members are 
// a head pointer to our linear linked list of SegmentNodes and an integer to act 
// as an array index that holds the current top of the stack.

#include "segment.h"

// used to create arrays of MAX size
const int MAX = 5;

struct SegmentNode
{
    Segment * segments;
    SegmentNode * next;
};

// interface for the stack
class Stack
{
   public:
    // constructor
    Stack();
    // destructor
    ~Stack();
    // push's a segment onto the stack
    int push(Segment & to_push);
    // pop's a segment off of the stack
    int pop(Segment & pop_to);
    // prints the segment on the current top of the stack
    int peek();
    // displays all segments currently on the stack
    int display();
   private:
    // head pointer to our list of Segment arrays
    SegmentNode * head;
    // array index for keeping track of the current top of the stack
    int top_index;
};
