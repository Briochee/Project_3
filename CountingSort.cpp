//Name: Rio Simpson
//Description: Implementation file for CountingSort class

//Libraries
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <utility>
#include <iterator>
#include <algorithm>
// #include <chrono>

//header file
#include "CountingSort.hpp"

/* Project Specifications
Method 4 (counting sort) is the only of these methods that isn't in-place. You'll need to read the integers 
from the data vector and insert them into a hash map, with the data value as the hash key, and a count of times 
that particular data value was seen as the hash value. So the first time you see a new value X in the data, 
you insert it into the hash using X as the key, and you set that key's hash value to 1. The second time you see X, 
you find that it's already in the hash, so you increment its hash value to 2. The third time you see X, you increment 
its hash value to 3, and so on.

Once you have a hash map of all the unique data values and the number of times each data value appeared in the data, 
iterate through the hash map, pushing the key-value pairs in the hash map to a vector. Then, sort that vector using 
std::sort (in an input with many duplicates, a vector of unique values will be much smaller than a vector of all the values). 
Finally, iterate through that vector finding P25, P50, and P75. You'll have to count how many data points you've seen along 
the way, since each element of the vector represents multiple data point, not just one. Finding the minimum and maximum should 
be self-explanatory.
*/

//constructor
CountingSort::CountingSort(){
    min = 0;
    p25 = 0;
    median = 0;
    p75 = 0;
    max = 0;
}

//sorting function
void CountingSort::countingSort(const std::string& header, std::vector<int> data){
    // //starting timer
    // auto start4 = std::chrono::high_resolution_clock::now();

    //unordered map for elements from vector, int is key, count is value
    std::unordered_map<int, int> inital;

    //constructing unordered map
    for (const int& value : data){
        if (inital[value] == 0){
            inital[value] = 1;
        } else {
            inital[value]++;
        }
    }

    //pushing key value pairs onto a vector
    std::vector<std::pair<int, int> > keyValue;
    for (std::unordered_map<int, int>::iterator it = inital.begin(); it != inital.end(); it++){
        keyValue.push_back(std::make_pair(it->first, it->second));
    }

    std::sort(keyValue.begin(), keyValue.end(),[](const std::pair<int, int>& a, const std::pair<int, int>& b){return a.first < b.first;});

    //assigning min and max value, does not changed based on count
    min = keyValue[0].first;
    max = keyValue[keyValue.size() - 1].first;

    //getting median index from size of input, p25 and p75 index from median index
    int medianIndex = (data.size() % 2 == 0) ? (data.size() / 2) - 1 : data.size() / 2;
    int p25_index = medianIndex/2;
    int p75_index = medianIndex + ((data.size() - medianIndex)/2);
    //using loop to iterate through vector, increment counts, if there is a match, assign correct value
    //creating counter for unique values that only show up once
    int current_count = 0, unique = 0;
    for (const std::pair<int, int>& item : keyValue){
        current_count += item.second;
        //checking if count matches with index of 25th percentile element and if p25 has been assigned
        if (current_count >= p25_index && p25 == 0){
            p25 = item.first;
        } else if (current_count >= medianIndex && median == 0){
            //checking if count matches with index of 50th percentile element and if median has been assigned
            median = item.first;
        } else if (current_count >= p75_index && p75 == 0){
            //checking if count matches with index of 75th percentile element and if p75 has been assigned
            p75 = item.first;
            // //end loop, no need to go futher
            // break;
        }
        //if the value has an occurence of only 1, increment unique counter
        if (item.second == 1){
            unique++;
        }
    }
    
    // //ending timer
    // auto end4 = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> duration4 = end4 - start4;
    // std::cout << "CountingSort Completed in: " << duration4.count() * 1000 << " milliseconds\n\n";

    //printiing out data as specified by project specifications
    std::cout << header << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "P25: " << p25 << std::endl;
    std::cout << "P50: " << median << std::endl;
    std::cout << "P75: " << p75 << std::endl;
    std::cout << "Max: " << max << std::endl;
    std::cout << "Unique: " << unique << std::endl;
}