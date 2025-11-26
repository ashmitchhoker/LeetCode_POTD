#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

//bottom up approach

int numberOfPaths(vector<vector<int>>& grid , int k){
    int n = grid.size() , m = grid[0].size();

    vector<vector<vector<int>>> t(n + 1 , vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));

    for(int sum = 0 ; sum < k ; sum++){
        t[n - 1][m - 1][sum] =  (sum + grid[n - 1][m - 1]) % k == 0;
    }
    for(int i = n - 1 ; i >= 0 ; i--){
        for(int j = m - 1 ; j >= 0 ; j--){
            if(i == n - 1 && j == m - 1) continue;
            for(int sum = 0 ; sum < k ; sum++){
                if(i == n - 1 && j == m - 1) continue;
                int currSum = (sum + grid[i][j]) % k;
                t[i][j][sum] = (t[i + 1][j][currSum] + t[i][j + 1][currSum]) % mod;
            }
        }
    }

    return t[0][0][0] % mod;
}
// vector<vector<vector<int>>> t;
// int recurseHelper(vector<vector<int>>& grid , int sum , vector<vector<vector<int>>>& t , int row , int col , int k){
//     int n = grid.size() , m = grid[0].size();
//     if(row > n - 1 || col > m - 1) return 0;

//     if(row == n - 1 && col == m - 1){
//         return (sum + grid[row][col]) % k == 0;
//     }

//     if(t[row][col][sum] != -1) return t[row][col][sum];

//     int right = recurseHelper(grid , (sum + grid[row][col]) % k , t , row , col + 1 , k);
//     int down = recurseHelper(grid , (sum + grid[row][col]) % k , t , row + 1, col , k);

//     return t[row][col][sum] = (right + down) % mod;
// }
// int numberOfPaths(vector<vector<int>>& grid , int k){
//     int n = grid.size() , m = grid[0].size();
//     t.assign(n , vector<vector<int>>(m , vector<int>(k , -1)));

//     return recurseHelper(grid , 0 , t , 0 , 0 , k);
// }


int main(){
    vector<vector<int>> grid = {{7 , 3 , 4 , 9} , {2 , 3 , 6 , 2} , {2 , 3 , 7 , 0}};

    cout << numberOfPaths(grid , 1);
}