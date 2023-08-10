#include<iostream>
#include<string>
#include<vector>
using namespace std;

string kthPermutation(int n, int k) {
    // Write your code here.
    int fact=1;
    vector<int> numbers;
    for(int i=1;i<n;i++){
        fact = fact*i;//if n=4. fact = 3!=6
        numbers.push_back(i);
    }
    numbers.push_back(n); //4 pushed
    string ans = "";
    k = k-1; //0th based indexing. so -1.
    while(true){
        ans = ans + to_string(numbers[k/fact]); //16/6=2 so 2nd index=3
        numbers.erase(numbers.begin() + k/fact);
        if(numbers.size()==0){
            break;
        }
        k = k%fact;
        fact = fact/numbers.size(); //6/3=2
    }
    return ans;
}
