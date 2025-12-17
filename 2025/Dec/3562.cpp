#include <bits/stdc++.h>
using namespace std;


void solve(int node , int parent , vector<vector<int>> & adj , vector<int> & present , vector<int> & future , int budget , vector<vector<vector<int>>> & dp){
    vector<pair<vector<int> , vector<int>>> childrenStatesProfit;
    for (int & child : adj[node])
    {
        solve(child , node , adj , present , future , budget , dp);

        // now we know value of dp[child][0/1][b] any budget
        childrenStatesProfit.push_back({dp[child][0] , dp[child][1]});
        // vector with max profit each child can do on a particular budget if parent is bought or not
    }
    
    for (int parent = 0; parent <= 1; parent++)
    {
        vector<int> bestProfitAtNode(budget + 1 , 0);
        // if not bought
        vector<int> ifNotBought(budget + 1 , 0);

        for (auto & child : childrenStatesProfit)
        {
            vector<int> temp(budget + 1 , 0);
            for (int used = 0; used < budget + 1; used++)
            {
                for (int take = 0; take + used < budget + 1; take++)
                {
                    temp[take + used] = max(temp[take + used] , child.first[take] + ifNotBought[used]);
                }
            }
            ifNotBought = std::move(temp);
        }
        for (int b = 0; b < budget + 1; b++)
        {
            bestProfitAtNode[b] = max(bestProfitAtNode[b] , ifNotBought[b]);
        }
        

        int price = (parent == 0) ? present[node] : present[node]/2;
        int profit = future[node] - price;

        if(price <= budget){
            vector<int> ifBought(budget + 1 , 0);

            for (auto & child : childrenStatesProfit)
            {
                vector<int> temp (budget + 1 , 0);
                for (int used = 0; used < budget + 1; used++)
                {
                    for (int take = 0; take + used < budget + 1; take++)
                    {
                        temp[take + used] = max(temp[take + used] , child.second[take] + ifBought[used]);
                    }
                }
                ifBought = std::move(temp);
            }

            for (int b = price; b < budget + 1; b++)
            {
                bestProfitAtNode[b] = max(bestProfitAtNode[b] , ifBought[b - price] + profit);
            }
            
        }

        dp[node][parent] = std::move(bestProfitAtNode);
        
    }
}
int maxProfit(int n , vector<int> & present , vector<int> & future , vector<vector<int>> & heirarchy , int budget){
    vector<vector<int>> adj(n + 1);

    for(vector<int> & emp : heirarchy){
        int boss = emp[0] , employee = emp[1];

        adj[boss - 1].push_back(employee - 1);
    }

    vector<vector<vector<int>>> dp(n + 1 , vector<vector<int>>(2 , vector<int>(budget + 1 , 0)));
    // [][][] emp , parent bought or not , current budget
    // max profit it can generate with that state from itself and its children

    for (int b = 0; b < budget + 1; b++)
    {
        dp[0][0][b] = 0;
    }
    
    solve(0 , -1 , adj , present , future , budget , dp);

    return dp[0][0][budget];
}
int main(){

    int n = 3;
    vector<int> present = {4 , 6 , 8} , future = {7 , 9 , 11};
    vector<vector<int>> heirarchy = {{1 , 2} , {1 , 3}};
    int budget = 10;
    cout << maxProfit(n , present , future , heirarchy , budget);
    return 0;
}