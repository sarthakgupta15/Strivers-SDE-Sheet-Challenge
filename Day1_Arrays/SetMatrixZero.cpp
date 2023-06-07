#include<iostream>
#include<vector>
using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<bool> rowZero(n), colZero(m);
    
    for(int i=0;i<n; i++){
        for(int j=0; j<m;j++){
            if(matrix[i][j]==0){
                rowZero[i] = colZero[j] = true;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(rowZero[i] || colZero[j]){
                matrix[i][j] = 0;
            }
        }
    }
}