#include <bits/stdc++.h>
using namespace std;

int maxPathScore(vector<vector<int>> & grid , int k ){

    int n = grid.size() , m = grid[0].size();

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1 , INT_MIN)));
    

    for (int i = n - 1 ; i >= 0 ; i--){
        for (int j = m - 1 ; j >= 0 ; j--){
            for (int cost = k ; cost >= 0 ; cost--){
                int newCost = cost + ((grid[i][j] > 0) ? 1 : 0);
                
                if(newCost > k) continue;

                if(i == n - 1 && j == m - 1){
                    dp[i][j][cost] = grid[i][j];
                    continue;
                }

                int next_best = max(dp[i + 1][j][newCost] , dp[i][j + 1][newCost]);

                dp[i][j][cost] = next_best != INT_MIN ? grid[i][j] + next_best : next_best;
            }
        }
    }

    return dp[0][0][0] == INT_MIN ? -1 : dp[0][0][0];

}

int main(){
    int k = 1;
    vector<vector<int>> grid = {{0 , 1} , {1 , 2}};

    cout << maxPathScore(grid , k);

    return 0;
}


// memoization dp

// int recurse(int row , int col , int cost , vector<vector<int>> & grid , int k , vector<vector<vector<int>>>& dp){
//     int n = grid.size() , m = grid[0].size();
    
//     if(row > n - 1 || col > m - 1) return INT_MIN;

//     int newCost = (grid[row][col] > 0) ? 1 : 0;

//     if(newCost + cost > k) return INT_MIN;

//     if(row == n - 1 && col == m - 1) return grid[row][col];

//     if(dp[row][col][cost] != -1) return dp[row][col][cost];

//     int down = recurse(row + 1 , col , cost + newCost , grid , k , dp);
//     int right = recurse(row , col + 1 , cost + newCost , grid , k , dp);

//     int newScore = max(down , right);

//     if(newScore == INT_MIN) return dp[row][col][cost] = INT_MIN;

//     return dp[row][col][cost] = grid[row][col] + newScore;
// }

// brute force recursion

// void recurse(int row , int col , vector<vector<int>> & grid , int k , int cost , int score , int & ans){
    
//     int n = grid.size() , m = grid[0].size();
    

//     if(row >= n || col >= m) return;

//     int curr_score = grid[row][col];

//     int curr_cost = (curr_score == 2) ? 1 : curr_score;

//     cost += curr_cost;

//     score += curr_score;
//     if(cost > k) return;


//     if (row == n - 1 && col == m - 1)
//     {
//         ans = max(ans , score);
//         cout << "cost is " << cost << " score is " << score << endl;
//         return;
//     }

//     recurse(row + 1 , col , grid , k , cost , score , ans);
//     recurse(row, col + 1 , grid , k , cost , score , ans);
// }
