#include<iostream>
#include<vector>
using namespace std;

 /*
        Time Complexity: O((m * n) * log(m * n))
        Space complexity: O(m * n)

        Where 'm' denotes the number of rows and 'n' denotes the number of columns of the matrix.

*/

int median(vector<vector<int>> &matrix, int m, int n)
{
    vector<int> spreadMatrix;

    // Transfer the elements
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            spreadMatrix.push_back(matrix[i][j]);
        }
    }

    // Sort to find the median
    sort(spreadMatrix.begin(), spreadMatrix.end());

    // Return the middle element
    return spreadMatrix[m * n / 2];
}

 