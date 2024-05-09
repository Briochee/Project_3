//Name: Rio Simpson
//Description: Implementation file for QuickSelect2 class

//Libraries
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <chrono>

//header file
#include "QuickSelect2.hpp"

/* Project Specifications
For method 3, replace the key k in your quickSelect's parameters with a set of keys you're looking for 
(use whatever container you want to hold them), which will include position 0, the 25% mark, the 50% mark, 
the 75% mark, the the last position of the data vector. Rewrite the recursive portion of quickSelect so that it 
checks whether it needs to recurse on both sides (if there are keys you need to find on both sides of the range being called), 
or if it only needs to recurse on one side. This may be tricky to work out, but once you figure out the algorithm, 
it's not really much coding to implement. Again, default to insertion sort once you reach a size of 20 or less.

For method 3, modify quickselect's recursive function to take a short list of keys rather than just one key. 
If you refer to p.322 in the textbook, you can replace the parameter int k with a small vector or list. 
Then rewrite the recursive portion so that quickselect calls itself on one or both sides, depending on whether 
there are positions you're searching for on both sides or only one.
*/

// //constructor
// QuickSelect2::QuickSelect2(){
//     // min = 0;
//     // p25 = 0;
//     // median = 0;
//     // p75 = 0;
//     // max = 0;
// }

//helper functions
void insertionSort2(std::vector<int>& data){
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
/* function not used
int median3_2(std::vector<int>& data, int left, int right){
    int mid = left + (right - left) / 2;

    if (data[left] > data[mid]){
        std::swap(data[left], data[mid]);
    }
    if (data[left] > data[right]){
        std::swap(data[left], data[right]);
    }
    if (data[mid] > data[right]){
        std::swap(data[mid], data[right]);
    }

    std::swap(data[mid], data[right - 1]);
    return right - 1;
} */

//function returns pivot index of value half way between left and right and partitions data to left and right of pivot
int partition2(std::vector<int>& data, int left, int right){
    //pivot
    int pivot = (left + right) / 2;
    //pivotValue
    int pivotValue = data[pivot];
    //move pivot to end
    std::swap(data[pivot], data[right]);
    //starting point, index value, not data value
    int pivotIndex = left;
    for (int j = left; j < right; j++){
        //if data[j] is smaller than pivot value, swap value at front starting point with value at back starting point
        if (data[j] < pivotValue){
            std::swap(data[j], data[pivotIndex]);
            pivotIndex++;
        }
    }
    
    //desired value for pivot point
    std::swap(data[pivotIndex], data[right]);
    return pivotIndex;
}

//quickselect function returns values at key indices, which are passed by keys vector
std::vector<int> quickSelect(std::vector<int>& data, int left, int right, std::vector<int> keys){
    if (right - left > 20){
        //getting pivot index
        int pivotIndex = partition2(data, left, right);
        
        std::vector<int> leftKeys, rightKeys;
        //pushing keys into respective vectors to be recusively called depending on relative position to pivot
        for (int key : keys) {
            if (key < pivotIndex) {
                //if less than pivot, push to leftKeys, recurse on the left
                leftKeys.push_back(key);
            } else if (key > pivotIndex) {
                //if more than pivot, push to rightKeys, recurse on the right
                rightKeys.push_back(key);
            }
        }
        
        std::vector<int> resultValues;
        //if leftKeys is not empty, recurse on left side
        if (!leftKeys.empty()) {
            std::vector<int> leftResult = quickSelect(data, left, pivotIndex - 1, leftKeys);
            //inserting values from leftResult into resultValues, values for the keys left of pivot
            resultValues.insert(resultValues.end(), leftResult.begin(), leftResult.end());
        }
        
        resultValues.push_back(data[pivotIndex]);
        //if rightKeys is not empty, recurse on right side
        if (!rightKeys.empty()) {
            std::vector<int> rightResult = quickSelect(data, pivotIndex + 1, right, rightKeys);
            //inserting values from rightResult into resultValues, values for the keys right of pivot
            resultValues.insert(resultValues.end(), rightResult.begin(), rightResult.end());
        }
        
        return resultValues;
    } else {
        //use insertion sort for small subarrays <= 20 items
        std::vector<int> subarray(data.begin() + left, data.begin() + right + 1);
        insertionSort2(subarray);
        std::vector<int> resultValues;
        for (int key : keys) {
            resultValues.push_back(subarray[key]);
        }
        return resultValues;
    }
}

//sorting function
void quickSelect2(const std::string& header, std::vector<int> data){
    // //starting timer
    // auto start3 = std::chrono::high_resolution_clock::now();

    //median index, smaller of the two if even input
    int medianIndex = data.size() / 2;

    //second quickSelect for p25
    int p25_index = medianIndex / 2;

    //third quickSelect for p75
    int p75_index = medianIndex + (data.size() - medianIndex) / 2;

    //storing min at position 0, p25 at position 1, median at position 2, p75 at position 3, max at position 4
    int minIndex = 0;
    int maxIndex = data.size() - 1;

    std::vector<int> keys{minIndex, p25_index, medianIndex, p75_index, maxIndex};

    //calling quickselect
    std::vector<int> resultValues = quickSelect(data, 0, data.size() - 1, keys);
    
    // //ending timer
    // auto end3 = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> duration3 = end3 - start3;
    // std::cout << "QuickSelect2 Completed in: " << duration3.count() * 1000 << " milliseconds\n";

    //printiing out data as specified by project specifications
    std::cout << header << std::endl;
    std::cout << "Min: " << resultValues[0] << std::endl;
    std::cout << "P25: " << resultValues[1] << std::endl;
    std::cout << "P50: " << resultValues[2] << std::endl;
    std::cout << "P75: " << resultValues[3] << std::endl;
    std::cout << "Max: " << resultValues[4] << std::endl;
}