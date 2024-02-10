
// Bryce Diedrich
// CS163 Program #2
// Feb 2 2024
//
// <- header comments go here
#include "queue.h"
#include <cstring>
#include <ostream>
#include <iostream>

using namespace std;

Queue::Queue()
{
    RecordNode * rear = nullptr;
}

Queue::~Queue()
{
    RecordNode * deleter = rear;
    RecordNode * inc = rear;

    if(rear == nullptr)
        return;

    while(inc != rear)
    {
        deleter = inc;
        releaseRecordNode(deleter);
        inc = inc->next;
    }
}

int Queue::enqueue(Record & to_enqueue)
{
    Record new_record;

    RecordNode * new_node = new RecordNode;
    new_node->record = &new_record;

    new_node->record->copyRecord(to_enqueue);

    if(rear == nullptr)
    {
        rear = new_node;
        new_node->next = rear;
        return 0;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
        new_node->next = rear->next;
    }
    
    return 0;
}

int Queue::dequeue(Record & to_dequeue)
{
    to_dequeue.copyRecord(*(rear->record));

    if(rear == nullptr)
    {
       return 1;
    }
    else if(rear == rear->next)
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
    cout << "Record at front of Queue: " << endl;
    rear->next->record->display();

    return 0;
}

int Queue::display()
{
    // create temp pointer to increment through the list
    RecordNode * inc = rear->next;
    int count;

    cout << "\e[1;4mDisplaying Queue From Front to Back:\e[0m" << endl << endl;
    
    // increment through the records list printing the name of each activity until
    // we reach the end of the list.
    while(inc != rear)
    {
        cout << "\e[1mRecord at Queue Position " << count << endl;
        inc->record->display();
        inc = inc->next;
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
    char * name = nullptr;
    char * notes = nullptr;
    int start_time = 0;
    int length_miles = 0;
}

Record::~Record()
{
    delete[] name;
    delete[] notes;
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
