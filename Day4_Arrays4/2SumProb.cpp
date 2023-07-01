/*
Brute Force Approach
#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector<vector<int>>ans;
   for(int i=0; i<arr.size(); i++){
      for(int j=i+1;j<arr.size();j++){
         if(arr[i]+arr[j]==s){
            vector<int>pair(2);
            pair[0] = arr[i];
            pair[1] = arr[j];
            ans.push_back(pair);
         }
      }
   }

   vector<vector<int>> res(ans.size(), vector<int>(2,0));
   for(int i=0;i<ans.size();i++){
      int a = ans[i][0], b=ans[i][1];
      res[i][0] = min(a,b);
      res[i][1] = max(a,b);
   }
   sort(res.begin(), res.end());
   return res;
}
*/

//Using HashMap

#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<vector<int>> pairSum(vector<int>&arr, int s){
    int n = arr.size();
    //Map to store frequency of elements
    map<int, int>hash; 
    //This will store the result
    vector<vector<int>>ans;
    for(int ele : arr){
        int count = hash[s-ele];
        vector<int> pair(2);
        pair[0] = ele;
        pair[1] = s-ele;
        while(count--){
            ans.push_back(pair);
        }
        hash[ele] += 1;
    }

    //This will store the final result.
    vector<vector<int>> res(ans.size(),vector<int>(2,0));
    for(int i=0;i<ans.size();i++){
        int a = ans[i][0], b = ans[i][1];
        res[i][0] = min(a,b);
        res[i][0] = max(a,b);
    }
    //Finally sorting each pair in 'res'.
    sort(res.begin(), res.end());
    return res;
}

