/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where 'N' denotes the number of elements of the array
*/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int LongestSubsetWithZeroSum(vector<int>arr) 
{
    // Map to store the previous sums
    unordered_map<int, int> presum;
 
    int sum = 0; // Initialize the sum of elements
    int maxLen = 0; // Initialize result
    int n = arr.size();
    // Traverse through the given array
    for (int i = 0; i < n; i++) {
        // Add current element to sum
        sum += arr[i];
 
        if (arr[i] == 0 && maxLen == 0)
            maxLen = 1;
        if (sum == 0)
            maxLen = i + 1;
 
        // Look for this sum in Hash table
        if (presum.find(sum) != presum.end()) {
            // If this sum is seen before, then update maxLen
            maxLen = max(maxLen, i - presum[sum]);
        }
        else {
            // Else insert this sum with index in hash table
            presum[sum] = i;
        }
    }
 
    return maxLen;
}

/*
    Time Complexity: O(N^2)
    Space Complexity: O(1)

    Where 'N' denotes the number of elements of the array
*/

/*
int LongestSubsetWithZeroSum(vector < int > arr)

{
  // Initialize result
  int maxLen = 0;
  int n = arr.size();

  // Pick a starting point
  for (int i = 0; i < n; i++) {

    // Initialize currSum for every starting point
    int currSum = 0;

    // Try all subarrays starting with 'i'
    for (int j = i; j < n; j++) {
      currSum += arr[j];

      // If currSum becomes 0,then update maxLen if required

      if (currSum == 0)
        maxLen = max(maxLen, j - i + 1);
    }
  }
  return maxLen;
}
*/