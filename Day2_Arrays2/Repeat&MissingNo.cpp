#include<iostream>
#include<vector>
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	sort(arr.begin(),arr.end());
	int m,r;
	for(int i=0; i<n;i++){
		if(arr[i]==arr[i+1]){
			r = arr[i];
		}
	}

	int currSum = 0;
	for(int i=0;i<n;i++){
		currSum += arr[i];
	}

	int actualSum = n*(n+1)/2;
	m = actualSum - (currSum - r);
	
	pair<int,int> ans;
	ans.first = m;
	ans.second = r;
	
	return ans;
}
