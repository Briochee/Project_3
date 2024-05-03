//Name: Rio Simpson
//Description: Header file for StdSort class

//Libraries
#include <vector>
#include <string>

/* Project Specifications
For method 1, just use std::sort and print out the appropriate data points. 
This is to ensure that you have the correct answer and are printing correctly, 
and to give you a baseline to time your other algorithms against.
*/

class StdSort{
    public:
        //constructor
        StdSort();

        //StdSort.cpp, containing the function void stdSort (const std::string & header, std::vector<int> data)
        void stdSort(const std::string& header, std::vector<int> data);

    private:
        //container to hold data for printing
        std::vector<int> data_;
};