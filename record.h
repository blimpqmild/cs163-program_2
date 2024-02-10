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

class Record
{
   public:
    // constructor
    Record();
    // destructor
    ~Record();
    // create a new record
    int createRecord(char * name, char * notes, int start_time, int length_miles);
    // make a copy of a record
    int copyRecord(Record & copy_from);
    // print a record
    int display();
   private:
    int copyString(char * copy_from, char * &copy_to);
    // string that specifies the name of a record
    char * name;
    // string to hold notes on a trip
    char * notes;
    // start time of the trip
    int start_time;
    // length of the trip in hours
    int length_miles;
};
