#include <bits/stdc++.h>
using namespace std;

int countTrapezoids(vector<vector<int>>& points) {
    const long long MOD = 1000000007;

    // sort points by y-coordinate
    vector<vector<int>> newpoints = points;
    sort(newpoints.begin(), newpoints.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    });
    
    int curr = 0;
    int prev = newpoints[0][1];

    vector<long long> rowCounts; 
    for (int i = 0; i < newpoints.size(); i++) {
        if (prev == newpoints[i][1]) curr++;
        else {
            if (curr > 1) rowCounts.push_back(curr);
            prev = newpoints[i][1];
            curr = 1;
        }
    }
    if (curr > 1) rowCounts.push_back(curr);
    
    int n = rowCounts.size();
    if (n < 2) return 0;

    vector<long long> comb(n);
    for (int i = 0; i < n; i++) {
        comb[i] = (rowCounts[i] * (rowCounts[i] - 1) / 2) % MOD;
    }

    vector<long long> suffix(n+1, 0);
    for (int i = n-1; i >= 0; i--) {
        suffix[i] = (suffix[i+1] + comb[i]) % MOD;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + comb[i] * suffix[i+1]) % MOD;
    }
    
    return (int)ans;
}


int main(){
    vector<vector<int>> points = {{1 , 0} , {2 , 0} , {3 , 0} , {2 , 2} , {3 , 2}};
    cout << countTrapezoids(points);
    return 0;
}