#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    vector<int>majorityElement;
    unordered_map<int,int> freq;
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    for(auto i: freq){
        if(i.second > n/3){
            majorityElement.push_back(i.first);
        }
    }
    return majorityElement;
}