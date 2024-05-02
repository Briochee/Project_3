//Name: Rio Simpson
//Main file for testing

//Libraries
#include <chrono>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

//Header Files
#include "StdSort.hpp"
#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "CountingSort.hpp"

int main(){
    //extracting data from text flile
    std::ifstream input_data("test_input.txt");
    std::vector<int> read_data;

    //throw away introductory line
    std::string throwAway;
    std::getline(input_data, throwAway);

    if (input_data.is_open()) {
        int value;
        while (input_data >> value){
            read_data.push_back(value);
        }

        input_data.close();
    }

}