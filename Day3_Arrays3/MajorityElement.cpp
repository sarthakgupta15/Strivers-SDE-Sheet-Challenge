/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where 'N' is the size of array/list.
*/
#include<iostream>
#include<unordered_map>
using namespace std;

int findMajorityElement(int arr[], int n) {	
	// Declaring unordered map to store the frequency of elements.
	unordered_map<int, int> hashMap;

	// Iterating each element in the array to count frequencies.
	for(int i = 0; i < n; i++) {	
		// Storing frequency of each element.
		hashMap[arr[i]]++;

		// If frequency of the element is greater than 'n' / 2, then return the element.
		if(hashMap[arr[i]] > n/2) {
			return arr[i];
		}
	}

	// If no majority element found, return -1.
	return -1;
}