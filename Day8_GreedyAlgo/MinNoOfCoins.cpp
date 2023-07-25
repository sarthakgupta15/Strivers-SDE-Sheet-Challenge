/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where 'N' is the given amount to be changed.
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> MinimumCoins(int n)
{
    // Array to store denominations.
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<int> ans;
    int m = denominations.size();

    // Pick coins in decreasing order of their values.
    for (int i = m - 1; i >= 0; i--)
    {
        while (n >= denominations[i])
        {
            n = n - denominations[i];
            ans.push_back(denominations[i]);
        }
    }

    return ans;
}
