// Bryce Diedrich
// CS163 Program #2
// Feb 2 2024
//
// <- header comments go here (to be added later)

#include "stack.h"
#include <ostream>
#include <iostream>
#include <cstring>

using namespace std;

Stack::Stack()
{
    head = nullptr;
    top_index = 0;
}

Stack::~Stack()
{
    SegmentNode * inc = head;
    SegmentNode * tmp;
    int tmp_index = top_index - 1;

    // outer while loop traverses the LLL 
    while(!(inc == nullptr))
    {
        // inner fo
        for(tmp_index; tmp_index >= 0; --tmp_index)
        {
            inc->segments[tmp_index].~Segment();
        }
        tmp = inc;
        inc = inc->next;
        delete[] tmp->segments;
        delete tmp;
        tmp_index = MAX-1;
    }
    cout << endl;
}

int Stack::push(Segment & to_push)
{
    if(top_index == MAX || head == nullptr)
    {
        SegmentNode * tmp = new SegmentNode;
        tmp->next = head;
        head = tmp;
        head->segments = new Segment[MAX];
        top_index = 0;
        head->segments[top_index].copySegment(to_push);
        ++top_index;
    }
    else
    {
        head->segments[top_index].copySegment(to_push);
        ++top_index;
    }

    return 0;
}

int Stack::pop(Segment & pop_to)
{
    if(top_index == 0)
    {
        if(head->next == nullptr)
            return 1; //error: nothing left to pop
            
        SegmentNode * deleter = head;
        head = head->next;
        
        top_index = MAX-1;
        pop_to.copySegment(head->segments[top_index]);

        delete[] deleter->segments;
        delete deleter;
            

    }
    else
    {
        --top_index;
        pop_to.copySegment(head->segments[top_index]);
    }
    return 0;
}

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

Segment::Segment()
{
    char * transit_type = nullptr;
    char * location_start = nullptr;
    char * location_end = nullptr;
    bool runs_on_weekends = false;
}

Segment::~Segment()
{
    delete[] transit_type;
    delete[] location_start;
    delete[] location_end;
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
