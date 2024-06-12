#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        //Making a hashmap to keep track of each num in arr1 and how much times it popped up
        std::unordered_map<int, int> freqMap; //(key: num, value: count)
        for (int num : arr1) {
            freqMap[num]++; //adding to the count of the current num
        }

        std::vector<int> result;

        //making the result vector based on arr2 order
        for (int num : arr2) { //going through each num in arr2
            while (freqMap[num] > 0) //Checking if that num exist in the unordered map
            { 
                result.push_back(num); //adds the num into result
                freqMap[num]--; //it decrements the current count of num to prevent a infinite loop
            }
        }

        //Storing what is in arr1 but not arr2
        std::vector<int> remainingElements; 
        for (auto& pair : freqMap) { //iterating through each key-value pair in freqMap
            while (pair.second > 0) { //checks if the remainder keys have a counter of more than 0
                remainingElements.push_back(pair.first); //that key/num gets pushed back into the vector 
                pair.second--;
            }
        }

        //Sort the remaining elements
        std::sort(remainingElements.begin(), remainingElements.end());

        result.insert(result.end(), remainingElements.begin(), remainingElements.end()); //Inserts the begining of remainingElements to the end of remainingElements to the end of result

        return result;
    }
};
