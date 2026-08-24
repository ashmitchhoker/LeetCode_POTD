#include <bits/stdc++.h>
using namespace std;

// recursive function max(i) which will return the maxi diff from here
// this will be max(s[i] - max(i + 1) , max(i + 1));
// max[n - 1] = s[n - 1] // full prefix

// ans = maxdiff[1];


int maxiDiff(vector<int> & psum , int i , vector<int> & dp){
    int n = psum.size();
    if (i == n - 1)
    {
        return psum[n - 1];
    }

    if (dp[i] != INT_MIN)
    {
        return dp[i];
    }
    
    dp[i] = max(maxiDiff(psum , i + 1 , dp) , psum[i] - maxiDiff(psum , i + 1 , dp));

    return dp[i];
}

int stoneGameVIII(vector<int>& stones) {
    int n = stones.size();

    vector<int> psum = stones;

    
    for (int i = 1; i < n; i++)
    {
        psum[i] += psum[i - 1];
    }

    vector<int> dp(n , INT_MIN);

    return maxiDiff(psum , 1 , dp);
}


int main(){
    vector<int> stones = {-1,2,-3,4,-5};

    cout << stoneGameVIII(stones);
    return 0;
}

