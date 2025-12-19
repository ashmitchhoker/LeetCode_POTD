#include <bits/stdc++.h>
using namespace std;

long long maxProfit(vector<int> & prices , vector<int> & strategy , int k){
    int n = prices.size();
    long long base = 0;
    long long curr = 0;

    long long sub = 0;

    long long ans = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        base += 1LL * prices[i] * 1LL * strategy[i];
        if (i < k)
        {
            sub += 1LL * prices[i] * 1LL * strategy[i];
        }

        if (i >= k/2 && i < k)
        {
            curr += 1LL * prices[i];
        }
    }
    curr += base - sub;
    ans = max(curr , base);
    for (int i = 1; i + k <= n; i++)
    {
        int right = i + k - 1;
        curr += 1LL * prices[i - 1] * strategy[i - 1] - 1LL * prices[right] * 1LL * strategy[right] + 1LL * prices[right] - 1LL * prices[i - 1 + k/2];

        ans = max(ans , curr);
    }

    return ans;
    
}

int main(){
    vector<int> prices = {4 , 2 , 8} , strategy = {-1 , 0 , 1};

    int k = 2;

    cout << maxProfit(prices , strategy , k);

    return 0;
}