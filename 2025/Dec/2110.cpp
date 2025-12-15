#include <bits/stdc++.h>
using namespace std;


long long getDescentPeriods(vector<int>& prices){
    int n = prices.size();

    long long ans = n;

    int period = 1;

    int left = 0;
    

    while(left < n){
        while (left + 1 < n && prices[left] - prices[left + 1] == 1)
        {
            left++;
            period++;
        }
        long long n = period - 1;

        if(n == 1) ans += 1;
        else ans += n * (n + 1)/2;

        period = 1;
        left++;
    }
    return ans;

}

int main(){
    vector<int> prices = {1};
    cout << getDescentPeriods(prices);

    return 0;
}