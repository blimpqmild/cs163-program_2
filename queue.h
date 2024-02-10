// Bryce Diedrich
// CS163 Program #2
// Feb 2 2024
//
// This file provides the ADT for the transit trip records.
//
// Our Queue class and RecordNode struct provides the queue data structure
// implemeted as a circular linked list. The queue class provides the basic
// interface of the queue with operations like enqueue, dequeue, etc via
// it's public interface. The sole data member is a rear pointer to our
// circular linked list of RecordNodes.
//
// Our Record class holds all the information about a record among it's
// private data members. It also provides some basic operations for creating
// and copying records via it's public interface.

#include "record.h"

// node for a list of record objects
struct RecordNode
{
    Record * record;
    RecordNode * next;
};

// interface for the queue
class Queue
{
   public:
    // constructor
    Queue();
    // destructor
    ~Queue();
    // adds a record to the back of the queue
    int enqueue(Record & to_enqueue);
    // retrieves a record from the front of the queue
    int dequeue(Record & to_dequeue);
    // prints the record at the front of the queue
    int peek();
    // displays all records currently in the queue
    int display();
   private:
    int releaseRecordNode(RecordNode * deleter);
    // rear pointer to our circular linked list
    RecordNode * rear;
};
