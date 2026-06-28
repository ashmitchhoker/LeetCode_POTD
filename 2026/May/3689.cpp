#include <bits/stdc++.h>
using namespace std;

long long maxTotalValue(vector<int>& nums, int k) {
    int maxi = nums[0] ;
    int mini = nums[0];
    
    for (int i = 1; i < nums.size(); i++)
    {
        maxi = max(maxi , nums[i]);
        mini = min(mini , nums[i]);
    }
    long long ans = (long long) (k) * (long long)(maxi - mini);

    return ans;
}

int main(){
    vector<int> nums = {1 , 3 , 2};
    int k = 3;

    cout << maxTotalValue(nums , k);

    return 0;
}