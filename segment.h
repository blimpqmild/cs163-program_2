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
// 
// Our Segment class holds all the information about a segment among it's
// private data members. It also provides some basic operations for creating
// and copying segments via it's public interface.

class Segment
{
   public:
    // constructor
    Segment();
    // destructor
    ~Segment();
    // creates a new segment
    int createSegment(char * transit_type, char * location_start, char * location_end, bool runs_on_weekends);
    // make a copy of a segment
    int copySegment(Segment & copy_from);
    // display a segment
    int display();
   private:
    int copyString(char * copy_from, char * &copy_to);
    // string that specifies the type of transit
    char * transit_type;
    // string that specifies the start location of a segment
    char * location_start;
    // string that specifies the end location of a segment
    char * location_end;
    // does this segment operate on the weekend? bool holds true or false
    bool runs_on_weekends;
};
