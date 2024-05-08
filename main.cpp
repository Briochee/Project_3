//Name: Rio Simpson
//Main file for testing

//Libraries
#include <chrono>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>

//Header Files
#include "StdSort.hpp"
#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "CountingSort.hpp"

int main(){
    //extracting data from text flile
    std::ifstream input_data("inputs/test_input.txt");
    std::vector<int> read_data;

    //throw away introductory line
    std::string header;
    std::getline(input_data, header);

    if (input_data.is_open()) {
        int value;
        while (input_data >> value){
            read_data.push_back(value);
        }

        input_data.close();
    }

    StdSort myData1;
    //calling function
    myData1.stdSort(header, read_data);

    QuickSelect1 myData2;
    //calling function
    myData2.quickSelect1(header, read_data);

    QuickSelect2 myData3;
    //calling function
    myData3.quickSelect2(header, read_data);

    CountingSort myData4;
    //calling function
    myData4.countingSort(header, read_data);
}