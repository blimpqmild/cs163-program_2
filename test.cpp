#include "stack.h"
#include "queue.h"
#include <ostream>
#include <iostream>
#include <cstring>
#include <unistd.h>

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
    char again;

    do
    {
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

        cout << "Running push(Segment & to_push) method..." << endl;
        sleep(1);
        push_result = my_trip.push(to_add);


        if(push_result == 0)
        {
            cout << "Method call returned success!";
            sleep(1);
            cout << endl;
        }
        else
        {
            cout << "Method call has unrecognized error!";
            sleep(1);
            cout << endl;
        }

        cout << "Run again? (y/n): ";
        sleep(1);
        cin >> again; cin.ignore();
    }while(again == 'y' || again == 'Y');
    
    cout << "Returing to main menu!" << endl;
    sleep(1);
    cout << endl;
    return push_result;
}

int stack_run_pop(Stack & my_trip)
{
    Segment pop_to;
    char again;
    int push_result;
    
    do
    {
        cout << "Running push(Segment & pop_to);";
        sleep(1);
        push_result = my_trip.pop(pop_to);

        if(push_result == 0)
        {
            cout << "Method call returned success!";
            sleep(1);
            cout << endl;
            cout << "The following segment was popped from the stack:";
            sleep(1);
            cout << endl;
            pop_to.display();
            sleep(1);
        }
        else if(push_result == 1)
        {
            cout << "Method call returned a value of 1! This indicates there is nothing left on the stack to pop!";
            sleep(1);
            cout << endl;
        }
        
        cout << "Run again? (y/n): ";
        sleep(1);
        cin >> again; cin.ignore();
    }while(again == 'y' || again == 'Y');

    cout << "Returing to main menu!" << endl;
    sleep(1);
    cout << endl;
    return push_result;
}

int stack_run_peek(Stack & my_trip)
{
    int push_result;
    char again;

    do
    {
        cout << "Running peek(). The segment on the top of the stack will be displayed below..." << endl;
        sleep(1);
        push_result = my_trip.peek();
        cout << endl;

        if(push_result == 0)
        {
            cout << "Method call returned success!";
            sleep(1);
            cout << endl;
        }
        else if(push_result == 1)
        {
            cout << "Method call returned a value of 1! This indicates there are no segments on the stack to display!";
            sleep(1);
            cout << endl;
        }
        
        cout << "Run again? (y/n): ";
        sleep(1);
        cin >> again; cin.ignore();
    }while(again == 'y' || again == 'Y');
    
    return 0;
}

int stack_run_display(Stack & my_trip)
{
    int result;

    cout << "\e[1;4mDisplaying Stack From Top to Bottom\e[0m" << endl;
    sleep(1);
    result = my_trip.display();
    cout << endl;

    if(result == 0)
    {
            cout << "Method call returned success!";
            sleep(1);
            cout << endl;
    }
    else if(result = 1)
    {
            cout << "Method call returned a value of 1! This indicates there are no segments on the stack to display!";
            cout << endl << endl;
            sleep(1);
    }
    else
    {
            cout << "Unrecognized error!";
            sleep(1);
            cout << endl << endl;
    }

    return 0;
}

int queue_run_enqueue(Queue & my_queue)
{
    Record to_add;
    char name[100];
    char notes[100];
    char again;
    int start_time;
    int length_miles;
    int result;

    do
    {
        cout << "To test the enqueue function, first we must create a record."
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

        cout << "Running enqueue(Record & to_enqueue) method...";
        sleep(1);
        cout << endl;
        result = my_queue.enqueue(to_add);


        if(result == 0)
        {
            cout << "Method call returned success!";
            sleep(1);
            cout << endl;
        }
        else
        {
            cout << "Method call has unrecognized error!";
            sleep(1);
            cout << endl;
        }

        cout << "Run again? (y/n): ";
        sleep(1);
        cin >> again; cin.ignore();
    }while(again == 'y' || again == 'Y');
    return 0;
}

int queue_run_dequeue(Queue my_queue)
{
    Record dequeued_record;
    int result;
    char again;

    do
    {
        cout << "Running dequeue(Record & dequeue_to) method..." << endl;
        sleep(1);
        result = my_queue.dequeue(dequeued_record);
        cout << endl;

        if(result == 0)
        {
            cout << "Method call returned success!" << endl;
            sleep(1);
            cout << "The following record was dequeued from the queue:" << endl;
            sleep(1);
            dequeued_record.display();
            sleep(1);
        }
        else if(result == 1)
        {
            cout << "Method call returned a value of 1! This indicates that there are no records on the queue to pop!" << endl;
            sleep(1);
        }
        else
        {
            cout << "Unrecognized error!" << endl;
            sleep(1);
        }

        cout << "Run again? (y/n): ";
        cin >> again; cin.ignore();
        sleep(1);
        cout << endl;
    }while(again == 'y' || again == 'Y');

    return 0; 
}

int queue_run_peek(Queue & my_queue)
{
    int result;
    char again;

    do
    {
        cout << "Running peek()..." << endl;
        cout << "Displaying record at the front of the queue:" << endl;
        sleep(1);

        result = my_queue.peek();

        if(result == 0)
        {
            cout << "Method call returned success!" << endl;
            sleep(1);
        }
        else if(result == 1)
        {
            cout << "Method call returned a value of 1! That means there are no records on the queue to peek!" << endl;
            sleep(1);
        }
        else
        {
            cout << "Unrecognized error!" << endl;
            sleep(1);
        }

        cout << "Again? (y/n): ";
        cin >> again; cin.ignore();
        cout << endl;

    }while(again == 'y' || again == 'Y');

    return 0;
}

int queue_run_display(Queue & my_queue)
{
    my_queue.display();
    cout << endl;

    return 0;
}

int main()
{
    Stack my_trip;
    Queue my_queue;
    int response;
    char again;
    int method_result;
    
    do{
        cout <<            "-------------------------------------------------------------" << endl
             << "| " << "\e[1;4m" << "Select a function below by entering the associated number" << "\e[0m" << " |" << endl
             << "| " << "\e[1m" <<   "Enter 0 to exit                                          " << "\e[0m" << " |" << endl
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
            case 0:
                cout << "Goodbye!" << endl;
                break;
            case 1:
                method_result = stack_run_push(my_trip);
                break;
            case 2:
                method_result = stack_run_pop(my_trip);
                break;
            case 3:
                method_result = stack_run_peek(my_trip);
                break;
            case 4:
                method_result = stack_run_display(my_trip);
                break;
            case 5:
                method_result = queue_run_enqueue(my_queue);
                break;
            case 7:
                method_result = queue_run_peek(my_queue);
                break;
            case 6:
                method_result = queue_run_dequeue(my_queue);
                break;
            case 8:
                method_result = queue_run_display(my_queue);
                break;
        }


    }while(response != 0);
    
    return 0;
}
