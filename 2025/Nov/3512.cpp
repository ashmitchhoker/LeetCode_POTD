#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums , int k){
    int n = nums.size();

    int sum = 0;
    for(int num : nums) sum += num;

    return sum % k;
    
}

int main(){
    vector<int> nums = {3 , 9 , 7};
    cout << minOperations(nums , 5);
    return 0;
}