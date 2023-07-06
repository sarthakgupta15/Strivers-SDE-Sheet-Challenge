#include <iostream>
#include<vector>
#include <unordered_map>
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n = arr.size();
    unordered_map<int,int> prefXor;
    int ans=0;
    int currXor=0;
    prefXor[0]++;
    for(int i=0;i<n;i++){
        currXor= currXor^arr[i];
        int req = x^currXor;
        ans+=prefXor[req];
        prefXor[currXor]++;
    }
    return ans;
}

/*
    Time Complexity : O(N ^ 2)
    Space Complexity : O(1)
    
    Where 'N' denotes the number of elements in the given array.
*/
/*
int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    int ans = 0;
	
    // Traverse through each subarray
    for (int i = 0; i < n; i++)
    {
        // The variable currentXor stores the XOR of the current subarray 
        int currentXor = 0;
        
    	for (int j= i; j < n ;j++)
        { 	
            
            currentXor = currentXor ^ arr[j];
      		
            // Check if currentXor is equal to x 
            if(currentXor == x)
            {
                ans++;
            }
        }
    }
	
    // Return the variable ans
    return ans;
}
*/