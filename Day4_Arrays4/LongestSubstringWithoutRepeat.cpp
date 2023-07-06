/*
    Time Complexity : O(N)
    Space Complexity : O(K)

    where N is the length of input string and
    K is the number of unique characters in the string
*/
#include<iostream>
#include<string>
#include <unordered_map>
using namespace std;
//Sliding Window
int uniqueSubstrings(string input) 
{
    int n = input.length();
    unordered_map<char, int> set;
    int ans = 0, i = 0, j = 0;

    while (i < n && j < n) 
    {
        // Try to extend the range [i,j]
        if (set.find(input[j]) == set.end()) 
        {
            set[input[j]] = 1;
            ans = max(ans, j - i + 1);
            j++;
        } else 
        {
            set.erase(input[i]);
            i++;
        }
    }
    return ans;
}

/*
    Time Complexity - O(N^3)
    Space Complexity - O(N)

    where N is the length of the string.
*/
/*
#include <unordered_map>

bool allUnique(string input, int start, int end)
{
    //For storing every character of string
    unordered_map<char, int> set;

    for (int i = start; i < end; i++)
    {
        char ch = input[i];
        //If a character is already there then we have a found duplicates
        //so we need to return false
        if (set.find(ch) != set.end()) 
        {
            return false;
        }
        set[ch] = 1;
    }
    return true;
}

int uniqueSubstrings(string input)
{
    int n = input.length();
    int ans = 0;

    //Check for every possible substring
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j <= n; j++) 
        {
            //If substring contains unique characters then update the maximum.
            if (allUnique(input, i, j)) 
            {
                ans = max(ans, j - i);
            }
        }
    }
    
    return ans;
}
*/