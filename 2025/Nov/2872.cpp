#include <bits/stdc++.h>
using namespace std;

int dfs(int node , int parent , vector<vector<int>>& adj , int k , vector<int>& values , int & count){
    int sum = values[node];
    for(auto child : adj[node]){
        if(child != parent){
            sum += dfs(child , node , adj , k , values , count);
            sum %= k;
        }
    }

    sum %= k;

    if(sum == 0){
        count++;
    }
    return sum;
}
int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    
    vector<vector<int>> adj(n);
    
    for(vector<int> edge : edges){
        int u = edge[0] , v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int count = 0;

    dfs(0 , -1 , adj , k , values , count);
    return count;
}


int main(){
    int n = 5;
    vector<vector<int>> edges = {{0 , 2} , {1 , 2} , {1 , 3} , {2 , 4}};
    vector<int> values = {1 , 8 , 1 , 4 , 4};
    int k = 6;
    cout << maxKDivisibleComponents(n , edges , values ,k);

    return 0;
}