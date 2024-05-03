//Name: Rio Simpson
//Description: Implementation file for StdSort class

//Libraries
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//header file
#include "StdSort.hpp"

/* Project Specifications
For method 1, just use std::sort and print out the appropriate data points. 
This is to ensure that you have the correct answer and are printing correctly, 
and to give you a baseline to time your other algorithms against.
*/

//constructor
StdSort::StdSort(){

}

//sorting function
void StdSort::stdSort(const std::string& header, std::vector<int> data){
    //using std::sort
    std::sort(data.begin(), data.end());
    if (data.size() % 2 == 0){
        int median_index = (data.size() - 1)/2;
        //calculating median to be lower of middle value
        int median = data[median_index];
        //calculating 25th percentile to be middle value of lower hald
        int percentile25 = data[median_index/2];
        //calculating 7th percentile to be middle value of upper half
        int percentile75 = data[median_index + ((data.size() - median_index)/2)];

       //pushing values into data_
        //storing min at position 0
        data_.push_back(data[0]);
        //storing 25th percentile at position 1
        data_.push_back(percentile25);
        //storing 50th percentile at position 2
        data_.push_back(median);
        //storing 75th percentile at position 3
        data_.push_back(percentile75);
        //storing max at position 4
        data_.push_back(data[data.size() - 1]);
    } else {
        int median_index = (data.size())/2;
        //calculating median to be lower of middle value
        int median = data[median_index];
        //calculating 25th percentile to be middle value of lower hald
        int percentile25 = data[median_index/2];
        //calculating 7th percentile to be middle value of upper half
        int percentile75 = data[median_index + ((data.size() - median_index)/2)];

        //pushing values into data_
        //storing min at position 0
        data_.push_back(data[0]);
        //storing 25th percentile at position 1
        data_.push_back(percentile25);
        //storing 50th percentile at position 2
        data_.push_back(median);
        //storing 75th percentile at position 3
        data_.push_back(percentile75);
        //storing max at position 4
        data_.push_back(data[data.size() - 1]);
    }

    //printiing out data as specified by project specifications
    std::cout << header << std::endl;
    std::cout << "Min: " << data_[0] << std::endl;
    std::cout << "P25: " << data_[1] << std::endl;
    std::cout << "P50: " << data_[2] << std::endl;
    std::cout << "P75: " << data_[3] << std::endl;
    std::cout << "Max: " << data_[4] << std::endl;
}