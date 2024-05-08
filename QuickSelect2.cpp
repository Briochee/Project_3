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

//constructor
QuickSelect2::QuickSelect2(){
    // min = 0;
    // p25 = 0;
    // median = 0;
    // p75 = 0;
    // max = 0;
}

//sorting function
void QuickSelect2::quickSelect2(const std::string& header, std::vector<int> data){
    //starting timer
    auto start3 = std::chrono::high_resolution_clock::now();

    //median index, smaller of the two if even input
    int medianIndex = (data.size() % 2 == 0) ? (data.size() / 2) - 1 : data.size() / 2;

    //second quickSelect for p25
    int p25_index = medianIndex / 2;

    //third quickSelect for p75
    int p75_index = medianIndex + ((data.size() - medianIndex)/2);

    //storing min at position 0, p25 at position 1, median at position 2, p75 at position 3, max at position 4
    std::vector<int> keys{0, p25_index, medianIndex, p75_index, static_cast<int>(data.size() - 1)};

    //calling quickselect
    std::vector<int> result = quickSelect(data, 0, data.size() - 1, keys);
    
    //ending timer
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration3 = end3 - start3;
    std::cout << "QuickSelect2 Completed in: " << duration3.count() * 1000 << " milliseconds\n\n";

    //printiing out data as specified by project specifications
    std::cout << header << std::endl;
    std::cout << "Min: " << result[0] << std::endl;
    std::cout << "P25: " << result[1] << std::endl;
    std::cout << "P50: " << result[2] << std::endl;
    std::cout << "P75: " << result[3] << std::endl;
    std::cout << "Max: " << result[4] << std::endl;
}

//helper functions
std::vector<int> QuickSelect2::quickSelect(std::vector<int>& data, int left, int right, std::vector<int> keys){
    std::vector<int> result;
    //for each value matched with its appropritate key, add to map and return
    if (data.size() <= 20){
        insertionSort(data);
        for (int key : keys) {
            if (key >= left && key <= right) {
                result.push_back(data[key]);
            }
        }
        return result;
    }

    //pivot made calling parition
    int pivot = partition(data, left, right);

    //vector to store keys and values left of pivot, and right of pivot
    std::vector<int> leftResult, rightResult;
    std::vector<int> leftKeys, rightKeys;

    //checking which side of pivot key is on
    for (int key : keys){
        if (key < pivot){
            leftKeys.push_back(key);
        } else if (key > pivot){
            rightKeys.push_back(key);
        } else {
            result.push_back(data[key]);
        }
    }

    //checking if recursive call needs to be made on both sides of pivot
    if (!leftKeys.empty() && !rightKeys.empty()){
        leftResult = quickSelect(data, left, pivot - 1, leftKeys);
        rightResult = quickSelect(data, pivot + 1, right, rightKeys);
    } else if (!leftKeys.empty()){
        //recursive call for left side of pivot
        leftResult = quickSelect(data, left, pivot - 1, leftKeys);
    } else if (!rightKeys.empty()){
        //recursive call for right side of pivot
        rightResult = quickSelect(data, pivot + 1, right, rightKeys);
    }

    //moving value from left result to return map
    result.insert(result.end(), leftResult.begin(), leftResult.end());
    //moving value from right result to return map
    result.insert(result.end(), rightResult.begin(), rightResult.end());

    return result;
}

int QuickSelect2::partition(std::vector<int>& data, int left, int right){
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

void QuickSelect2::insertionSort(std::vector<int>& data){
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