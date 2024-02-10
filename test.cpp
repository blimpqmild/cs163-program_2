#include "stack.h"
#include "queue.h"
#include <ostream>
#include <iostream>
#include <cstring>

using namespace std;

int stack_run_push(Stack & my_trip)
{
    Segment to_add;
    char transit_type[100];
    char location_start[100];
    char location_end[100];
    char response;
    bool runs_on_weekends;
    int push_result;


    cout << "To test the push function, first we must create a segment."
         << endl;
    
    cout << "Enter a transit type for this segment of the trip: ";
    cin.get(transit_type, 100); cin.ignore(100,'\n');
    cout << "Enter where the trip segment starts: ";
    cin.get(location_start, 100); cin.ignore(100,'\n');
    cout << "Enter where the trip segment ends: ";
    cin.get(location_end, 100); cin.ignore(100,'\n');
    cout << "Does this segment run on weekends? (y/n): ";
    cin >> response; cin.ignore(); 

    switch(response)
    {
        case 'Y': case 'y':
            runs_on_weekends = true;
            break;
        case 'N': case 'n':
            runs_on_weekends = false;
            break;
    }

    to_add.createSegment(transit_type, location_start, location_end, runs_on_weekends);

    push_result = my_trip.push(to_add);
    cout << endl;

    return push_result;
}

int stack_run_pop(Stack & my_trip, Segment & pop_to)
{
    my_trip.pop(pop_to);
    cout << endl;

    return 0;
}

int stack_run_peek(Stack & my_trip)
{
    my_trip.peek();
    cout << endl;
    
    return 0;
}

int stack_run_display(Stack & my_trip)
{
    my_trip.display();
    cout << endl;

    return 0;
}

int queue_run_enqueue(Queue & my_records)
{
    Record to_add;
    char name[100];
    char notes[100];
    int start_time;
    int length_miles;


    cout << "To test the enqueue function, fir,t we must create a record."
         << endl;
    
    cout << "Enter the Name of the segment in this record: ";
    cin.get(name, 100); cin.ignore(100,'\n');
    cout << "Enter any notes on the segment in this record: ";
    cin.get(notes, 100); cin.ignore(100,'\n');
    cout << "Enter the starting time of the segment in this record: ";
    cin >> start_time; cin.ignore(); 
    cout << "Enter the distance (miles) of this segment in this record: ";
    cin >> length_miles; cin.ignore(); 

    to_add.createRecord(name, notes, start_time, length_miles);

    my_records.enqueue(to_add);
    return 0;
}

int queue_run_display(Queue & my_record)
{
    my_record.display();
    cout << endl;

    return 0;
}

int main()
{
    Stack my_trip;
    Queue my_record;
    Segment popped_segment;
    //popped_segment.createSegment(" ", " ", " ", false);
    int response;

    do{
        cout <<            "-------------------------------------------------------------" << endl
             << "| " << "\e[1;4m" << "Select a function below by entering the associated number" << "\e[0m" << " |" << endl
             << "| " << "\e[94m" << "                                                          " << "\e[0m" << "|" << endl
             << "| " << "\e[1;4m" << "Stack.h Public Member Functions:" << "\e[0m" << "                          " <<  "|" << endl
             << "| " << "\e[94m" << "1. push(Segment & to_push)                                " << "\e[0m" << "|" << endl
             << "| " << "\e[93m" << "2. pop(Segment & pop_to)                                  " << "\e[0m" << "|" << endl
             << "| " << "\e[96m" << "3. peek()                                                 " << "\e[0m" << "|" << endl
             << "| " << "\e[92m" << "4. display()                                              " << "\e[0m" << "|" << endl
             << "| " << "\e[94m" << "                                                          " << "\e[0m" << "|" << endl
             << "| " << "\e[1;4m" << "Stack.h Public Member Functions:" << "\e[0m" << "                          " <<  "|" << endl
             << "| " << "\e[94m" << "5. enqueue(Record & to_enqueue)                           " << "\e[0m" << "|" << endl
             << "| " << "\e[92m" << "6. dequeue(Record & to_dequeue)                           " << "\e[0m" << "|" << endl
             << "| " << "\e[94m" << "7. peek()                                                 " << "\e[0m" << "|" << endl
             << "| " << "\e[91m" << "8. display()                                              " << "\e[0m" << "|" << endl
             <<            "-------------------------------------------------------------" << endl
             << "response: ";
        cin >> response; cin.ignore();
        cout << endl;

        switch(response)
        {
            case 1:
                stack_run_push(my_trip);
                break;
            case 2:
                stack_run_pop(my_trip, popped_segment);

                cout << "The following segment was popped from the stack:" << endl;
                popped_segment.display();
                break;
            case 3:
                stack_run_peek(my_trip);
                break;
            case 4:
                stack_run_display(my_trip);
                break;
            case 5:
                queue_run_enqueue(my_record);
                break;
            case 8:
                queue_run_display(my_record);
                break;
        }

    }while(response != 0);
    
    return 0;
}
