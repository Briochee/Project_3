//Name: Rio Simpson
//Description: Header file for QuickSelect2 class

//Libraries
#include <vector>
#include <string>

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

class QuickSelect2{
    public:
        //constructor
        QuickSelect2();

        //QuickSelect2.cpp, containing the function void quickSelect2(const std::string & header, std::vector<int> data)
        void quickSelect2(const std::string& header, std::vector<int> data);

    private:
        //container to hold data passed by value
        std::vector<int> data_;
};