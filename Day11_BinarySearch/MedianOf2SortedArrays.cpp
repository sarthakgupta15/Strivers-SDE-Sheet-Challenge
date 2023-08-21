//Brute-Force Approach
/*
    Time Complexity: O(('n' + 'm') * log('n' + 'm'))
    Space Complexity: O('n' + 'm')

    Where 'n' & 'm' are the sizes of the arrays.
*/
#include<iostream>
using namespace std;
#include <algorithm>
#include<vector>
double median(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();

    // Merge the arrays.
    vector<int> merged;
    for (int i = 0; i < n; i++)
    {
        merged.push_back(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        merged.push_back(b[i]);
    }

    sort(merged.begin(), merged.end());

    // Find median of combined array.
    int total = merged.size();
    if (total & 1)
    {
        return merged[total / 2];
    }

    double ans = merged[total / 2 - 1] + merged[total / 2];
    return ans / 2;
}
