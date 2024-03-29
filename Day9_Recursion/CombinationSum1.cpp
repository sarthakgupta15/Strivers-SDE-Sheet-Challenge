/*
    Time Complexity : O(N * (2 ^ N))
    Space Complexity :  O(N * (2 ^ N))

    Where 'N' denotes the number of elements in the array.
*/
#include<iostream>
using namespace std;
#include<vector>

void findSubsetsThatSumToKHelper(vector<int>& arr, vector<vector<int>> &ans, vector<int> curSubset, int k, int idx)
{
    if (idx == arr.size())
    {
        if (k == 0 && curSubset.size() != 0)
        {
            ans.push_back(curSubset);
        }
        return;
    }

    // Case when we do not include the current element in the subset.
    findSubsetsThatSumToKHelper(arr, ans, curSubset, k, idx + 1);

    // Case when we include the current element in the subset.
    curSubset.push_back(arr[idx]);
    findSubsetsThatSumToKHelper(arr, ans, curSubset, k - arr[idx], idx + 1);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr,int n, int k)
{

    // Vector to store the subsets that sum to 'k'.
    vector<vector<int>> ans;

    // Vector to store the current subset.
    vector<int> curSubset;
    findSubsetsThatSumToKHelper(arr, ans, curSubset, k, 0);
    return ans;
}