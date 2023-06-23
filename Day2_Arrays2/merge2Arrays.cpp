#include <iostream>
#include<vector>
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	int i = m-1;
	int j = n-1;
	int lastIndex = m + n - 1;

	while(j>=0){
		if(i>=0 && arr1[i]> arr2[j]){
			arr1[lastIndex] = arr1[i];
			i--;
		}
		else{
			arr1[lastIndex] = arr2[j];
			j--;
		}
		lastIndex--;
	}
	return arr1;
}

/*

	Time complexity: O((M+N) * log(M+N))
	Space complexity: O(1)

	Where M and N are the number of elements in ARR1 and ARR2 respectively.


vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {

	for (int i = 0; i < n; i++) {
		arr1[i + m] = arr2[i];
	}

	sort(arr1.begin(), arr1.end());
	return arr1;
}

*/