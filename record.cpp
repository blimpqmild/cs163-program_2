// Bryce Diedrich
// CS163 Program #2
// Feb 2 2024
//
// This file provides the implementation of the Queue and
// Record class methods
//
// The public methods of Queue implemented below are:
// - enqueue: takes a Record object by reference as input and places it
//            to the back of the queue
// - dequeue: takes a Record object by reference as input and removes
//            an object from the front of the queue and copies it to
//            the passed Record object.
// - peek:    takes no input. prints the data values of the record at the
//            front of the queue.
// - display: takes no input. prints the data values of all records in 
//            the queue.
//
// The public methods of Record implemented below are:
// - createRecord: takes two char * objects for the name and notes, and
//                 two ints for start time and length (miles) as input.
//                 these values are then copied into the private data members
//                 of the calling Record object.
// - copyRecord:   takes a Record object by reference as input and copies 
//                 it's data member values to the data members of the calling
//                 Record object.
// - display:      takes no input. displays the data member values of the 
//                 calling Record object.

#include "queue.h"
#include <cstring>
#include <ostream>
#include <iostream>

using namespace std;

Queue::Queue()
{
    this->rear = nullptr;
}

Queue::~Queue()
{
    RecordNode * inc = rear->next;
    RecordNode * next_node;

    while(!(inc == rear))
    {
        delete inc->record;
        next_node = inc->next;
        delete inc;
        inc = next_node;

    }

}

int Queue::enqueue(Record & to_enqueue)
{
    Record *new_record = new Record();
    RecordNode * new_node = new RecordNode();
    new_node->record = new_record;

    new_node->record->copyRecord(to_enqueue);

    if(rear == nullptr)
    {
        rear = new_node;
        new_node->next = rear;

        return 0;
    }
    else
    {
        new_node->next = rear->next;
        rear->next = new_node;
        rear = new_node;
    }
    
    return 0;
}

int Queue::dequeue(Record & to_dequeue)
{

    if(rear == nullptr)
    {
       return 1; // error: nothing to dequeue
    }

    to_dequeue.copyRecord(*(rear->next->record));

    if(rear == rear->next)
    {
        delete rear;
        rear = nullptr;
    }
    else
    {
        RecordNode * deleter = rear->next;

        rear->next = rear->next->next;
        delete deleter;
    }

    return 0;
}

int Queue::peek()
{
    if(rear == nullptr)
        return 1; //error: nothing to peek

    rear->next->record->display();

    return 0;
}

int Queue::display()
{
    // create temp pointer to increment through the list
    RecordNode * inc = rear->next;
    int count = 0;

    cout << "\e[1;4mDisplaying Queue From Front to Back\e[0m" << endl << endl;
    
    // increment through the records list printing the name of each activity until
    // we reach the end of the list.

    while(inc != rear)
    {
        cout << "\e[1mRecord at Queue Position " << count << endl;

        inc->record->display();
        inc = inc->next;
        ++count;
    }

    cout << "\e[1mRecord at Queue Position " << count << endl;
    inc->record->display();
    cout << endl;
   
    return 0;
}

int Queue::releaseRecordNode(RecordNode * deleter)
{
    return 0;
}

Record::Record()
{
    name = nullptr;
    notes = nullptr;
    start_time = 0;
    length_miles = 0;
}

Record::~Record()
{
    if(name != nullptr)
    {
        cout << " deleteing " << name << endl;
        delete[] name;
    }

    if(notes != nullptr)
    {
        cout << " deleteing " << notes << endl;
        delete[] notes;
    }
}

int Record::createRecord(char * name, char * notes, int start_time, int length_miles)
{
    int result = copyString(name, this->name);
    if(result != 0)
        return result;

    result = copyString(notes, this->notes);
    if(result != 0)
        return result;


    this->start_time = start_time;
    this->length_miles = length_miles;

   return 0; 
}

int Record::copyRecord(Record & copy_from)
{
    int result = copyString(copy_from.name, this->name);
    if(result != 0)
        return result;

    result = copyString(copy_from.notes, this->notes);
    if(result != 0)
        return result;

    this->start_time = copy_from.start_time;
    this->length_miles = copy_from.length_miles;
    
    return 0;
}

int Record::display()
{
    cout << "    Name: " << name << endl
         << "    Notes: " << notes << endl
         << "    Length (miles): " << length_miles << endl
         << "    Start Time: " << start_time << endl;

    return 0;
}

int Record::copyString(char * copy_from, char * &copy_to)
{
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
