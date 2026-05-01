#include <bits/stdc++.h>
using namespace std;


int maxRotateFunction(vector<int> & nums){
    int n = nums.size();

    int sum = 0;
    int x = 0;

    int cnt = 0;
    for (int i = 0; i < n ; i++)
    {
        sum += nums[i];
        x += cnt * nums[i];
        cnt++;
    }
    cout << x << endl;
    int right = n - 1;

    int ans = INT_MIN;
    

    int curr = 0;

    while (right >= 0)
    {
        curr = x + sum - n * nums[right];
        ans = max(ans , curr);

        x = curr;

        right--;
    }
    

    return ans;
    
}

int main(){
    vector<int> nums = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};

    cout << maxRotateFunction(nums);

    return 0;
}