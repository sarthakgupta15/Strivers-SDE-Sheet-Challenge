/*
    Time Complexity  : O(N)
    Space Complexity : O(N)

    Where N is the total number of elements in the given array.
*/
#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

int singleNonDuplicate(vector<int>& arr)
{
    // Declare a hashMap
    unordered_map<int, int> hashMap;

    // Store frequency of elements of array in hashMap
    for (int i = 0; i < arr.size(); i++)
    {
        hashMap[arr[i]]++;
    }

    // Find the element having frequency equal to 1 and return it
    for (auto key : hashMap)
    {
        if (key.second == 1)
        {
            return key.first;
        }
    }
}