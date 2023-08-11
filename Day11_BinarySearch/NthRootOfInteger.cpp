/*
    Time Complexity: O( N * log(M) )
    Space Complexity: O( 1 )

    Where 'N' and 'M' are given integers.
*/
#include<iostream>
using namespace std;

int NthRoot(int n, int m) {
    // 'ans' variable stores the 
    // nth root of m
    int ans = -1;
    
    // 's' and 'e' are the lower and upper
    // bounds of our search space
    int s = 1, e = m;
    
    while (s <= e) {
        int mid = (s + e) / 2;
        
        // 'x' stores the value of 
        // mid ^ n
        long long x = 1;
        
        // Iterating from '1' from 'n'
        // to get 'mid ^ n'
        for (int i = 1; i <= n; ++i) {
            x *= mid;
            
            // If 'x' is greater than 'm'
            // it's better to stop the loop
            // as obviously, multiplying 
            // x, further with 'mid' will increase it
            // more.
            if (x > 1LL * m) {
                break;
            }
        }
        // If 'x' becomes 'm', we have found the answer
        if (x == 1LL * m) {
            ans = mid;
            break;
        }
        // If 'x' is greater than 'm',
        // we should shift our search space
        // to lower integer values, otherwise higher.
        if (x > m) {
            e = mid - 1;
        } else
            s = mid + 1;
    }
    return ans;
}