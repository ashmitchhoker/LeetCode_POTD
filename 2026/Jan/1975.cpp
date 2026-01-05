#include <bits/stdc++.h>
using namespace std;


long long maxMatrixSum(vector<vector<int>> & matrix){
    long long sum = 0;

    int negatives = 0;
    int minAbsVal = INT_MAX;


    for (auto& row : matrix)
    {
        for (int val : row)
        {
            sum += abs(val);

            if (val < 0)
            {
                negatives++;
            }

            minAbsVal = min(minAbsVal , abs(val));
        }
    }

    if (negatives % 2)
    {
        sum -= 2 * minAbsVal;
    }
    
    
    return sum;
}


int main(){
    vector<vector<int>> matrix = {{1 , 2 , 3} , {-1 , -2 , -3} , {1 , 2, 3}};

    cout << maxMatrixSum(matrix);

    return 0;
}