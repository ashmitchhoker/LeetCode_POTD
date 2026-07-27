#include <bits/stdc++.h>
using namespace std;


int maxProduct(vector<int>& nums){
    int n = nums.size();
    int big1 = 0 , big2 = 0;
    
    for(int num : nums){
        if (num > big1)
        {
            big2 = big1;
            big1 = num;
        }
        else if(num > big2){
            big2 = num;
        }
    }
    
    return (big1 - 1) * (big2 - 1);
}

int main(){
    vector<int> nums = {3 , 7};
    cout << maxProduct(nums);
    return 0;
}