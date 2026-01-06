#include <bits/stdc++.h>
using namespace std;

int repeatedNTimes(vector<int> & nums){
    int right = 2;
    
    if(nums[0] == nums[nums.size() - 1]) return nums[0];
    while(right < nums.size()){
        int first = nums[right - 2];
        int second = nums[right - 1];
        int third = nums[right];

        if (first == second)
        {
            return first;
        }
        
        if (third == second)
        {
            return second;
        }
        if (third == first)
        {
            return first;
        }

        right ++;
    }

    return 0;
    
}


int main(){
    vector<int> nums = {5 , 1 , 5 , 2 , 5 , 3 , 5 , 4};
    cout << repeatedNTimes(nums);
}