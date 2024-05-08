//Name: Rio Simpson
//Description: Implementation file for QuickSelect1 class

//Libraries
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
// #include <chrono>

//header file
#include "QuickSelect1.hpp"

/* Project Specifications
For method 2, using quickSelect 3 times, the idea is simple: call quickSelect on the entire input with the middle of the vector as the key, k. 
This will give you the median, around which your vector will be partitioned. Then, call quickSelect on the half of the vector before 
the median with the 25% mark of the vector as k. Then, call quickSelect on the half of the vector after the median with the 75% mark as k. 
Then, search for the minimum only before the 25% mark, and the maximum only after the 75% mark. Default to insertion sort when quickSelect is 
recursively called on a range of size 20 or less (this means you'll have to write a small in-place insertion sort).

For method 2, find the median first. Then, on the same vector that's already partitioned around the median, call quickselect on the left half to 
find P25 and on the right half to find P75. Then, search the part of the vector beleft P25 for the min and above P75 for the max.
*/

//constructor
QuickSelect1::QuickSelect1(){
    this->min = 0;
    this->p25 = 0;
    this->median = 0;
    this->p75 = 0;
    this->max = 0;
}

//helper functions
void insertionSort(std::vector<int>& data){
    for (int i = 1; i < data.size(); i++){
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key){
            //move elements greater than key ahead
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}

int partition(std::vector<int>& data, int left, int right){
    //value at the pivot, kth smallest value
    int pivotValue = data[right];
    //starting point, index value, not data value
    int i = left;
    for (int j = left; j < right; j++){
        //if data[j] is smaller than pivot value, swap value at front starting point with value at back starting point
        if (data[j] < pivotValue) {
            //i     p       j
            //1 2 3 4 5 6 7 8
            std::swap(data[j], data[i]);
            i++;
        }
    }
    
    //desired value for pivot point
    std::swap(data[i], data[right]);
    return i;
}

int quickSelect(std::vector<int>& data, int left, int right, int key){
    //if the size is 20 or less, use std::sort and return the value at the key index
    if (right - left + 1 <= 20){
        insertionSort(data);
        return data[key];
    }

    int pivotIndex = partition(data, left, right);

    if (key == pivotIndex){
        return data[key];
    } else if (pivotIndex < key){
        return quickSelect(data, left, pivotIndex - 1, key);
    }
    return quickSelect(data, pivotIndex + 1, right, key);
}

//sorting function
void QuickSelect1::quickSelect1(const std::string& header, std::vector<int> data){
    // //starting timer
    // auto start2 = std::chrono::high_resolution_clock::now();

    //median index, smaller of the two if even input
    int medianIndex = (data.size() % 2 == 0) ? (data.size() / 2) - 1 : data.size() / 2;
    this->median = quickSelect(data, 0, data.size() - 1, medianIndex);

    //second quickSelect for p25
    int p25_index = medianIndex / 2;
    this->p25 = quickSelect(data, 0, medianIndex - 1, p25_index);

    //third quickSelect for p75
    int p75_index = medianIndex + ((data.size() - medianIndex)/2);
    this->p75 = quickSelect(data, medianIndex + 1, data.size() - 1, p75_index);

    //storing min and max for now sorted vector
    this->min = data[0];
    this->max = data[data.size() - 1];

    // //ending timer
    // auto end2 = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> duration2 = end2 - start2;
    // std::cout << "QuickSelect1 Completed in: " << duration2.count() * 1000 << " milliseconds\n\n";

    //printiing out data as specified by project specifications
    std::cout << header << std::endl;
    std::cout << "Min: " << this->min << std::endl;
    std::cout << "P25: " << this->p25 << std::endl;
    std::cout << "P50: " << this->median << std::endl;
    std::cout << "P75: " << this->p75 << std::endl;
    std::cout << "Max: " << this->max << std::endl;
}