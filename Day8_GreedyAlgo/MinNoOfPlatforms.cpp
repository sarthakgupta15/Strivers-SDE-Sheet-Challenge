#include<iostream>
using namespace std;

/*
    Time Complexity : O(N * log(N))
    Space Complexity : O(1)

    Where 'N' is the number of trains.
*/

#include <algorithm>

int calculateMinPatforms(int at[], int dt[], int n) {
    // Sort both the arrays.
    sort(at, at + n);
    sort(dt, dt + n);

    // Indicates the number of platforms needed at a time.
    int curNumOfPlatforms = 0;

    // Variable to store the final answer i.e. minimum number of platforms required.
    int minNumOfPlatforms = 0;

    int i = 0, j = 0;

    while (i < n && j < n) {

        // If the next event in sorted order is arrival, increment count of platforms needed.
        if (at[i] <= dt[j]) {
            curNumOfPlatforms++;
            i++;
        }

        // Else decrement count of platforms needed.
        else {
            curNumOfPlatforms--;
            j++;
        }

        // Update minimum number of platforms.
        minNumOfPlatforms = max(minNumOfPlatforms, curNumOfPlatforms);
    }

    // Return the minimum number of platforms.
    return minNumOfPlatforms;
}