#include <bits/stdc++.h>
using namespace std;


long long solve(int ind , vector<int> & prices , int k , int transactions , int state , vector<vector<vector<long long>>>& dp){

    if (ind >= prices.size() || transactions == k) {
        return (state == 0 ? 0 : LLONG_MIN);
    }
    if(dp[ind][state][transactions] != LLONG_MIN) {
        return dp[ind][state][transactions];
    }

    // lets skip
    
    long long skip = solve(ind + 1 , prices , k , transactions , state ,  dp);

    long long take = LLONG_MIN;
    

    if(transactions < k){
        if (state == 1)
        {
            // lets sell
            long long nxt = solve(ind + 1 , prices , k , transactions + 1, 0 , dp);
            if(nxt != LLONG_MIN) {
                take = max(nxt + 1LL*prices[ind], take);
            }
        }
        if (state == 2)
        {
            // lets buy
            long long nxt = solve(ind + 1 , prices , k , transactions + 1, 0 , dp);
            if(nxt != LLONG_MIN) {
                take = max(nxt - 1LL*prices[ind], take);
            }
        }

        if (state == 0)
        {
            long long shortSell = solve(ind + 1, prices, k, transactions, 2, dp);
            long long buyLong   = solve(ind + 1, prices, k, transactions, 1, dp);

            if (shortSell != LLONG_MIN)
                take = max(take, shortSell + prices[ind]);

            if (buyLong != LLONG_MIN)
                take = max(take, buyLong - prices[ind]);
        }
    }
    return dp[ind][state][transactions] = max(take , skip);
}

long long maximumProfit(vector<int> & prices , int k){
    int n = prices.size();
    vector<vector<vector<long long>>> dp(n + 1 , vector<vector<long long>>(3 , vector<long long>(k + 1, LLONG_MIN)));
    return solve(0 , prices , k , 0 , 0 , dp);
}

int main(){
    vector<int> prices = {12 , 16 , 19 , 19 , 8 , 1 , 19 , 13 , 9};
    int k = 3;

    cout << maximumProfit(prices , k);
}























// void solve(int ind , vector<int> & prices , int k , int transactions , int state , long long & maxi , long long profit){
//     // state 0 not in transaction , 1 means bought , 2 means sold a stock
//     if(ind >= prices.size() || transactions >= k){
//         if (state == 0)
//         {
//             maxi = max(profit , maxi);
//         }
//         return;
//     }

//     // lets skip

//     solve(ind + 1 , prices , k , transactions , state ,  maxi , profit);


//     if (state == 0)
//     {
        
//         maxi = max(profit , maxi);
//         // lets sell
//         solve(ind + 1 , prices , k , transactions , 2 , maxi , profit + 1LL*prices[ind]);
//         // lets buy
//         solve(ind + 1 , prices , k , transactions , 1 , maxi , profit - 1LL*prices[ind]);
//     }
    
//     if (state == 1)
//     {
//         // lets sell
//         solve(ind + 1 , prices , k , transactions + 1, 0 , maxi , profit + 1LL*prices[ind]);
//     }
//     if (state == 2)
//     {
//         // lets buy
//         solve(ind + 1 , prices , k , transactions + 1, 0 , maxi , profit - 1LL*prices[ind]);
//     }
// }