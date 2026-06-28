#include <bits/stdc++.h>
using namespace std;


vector<int> calculateMajorityRightSide(vector<int> & nums , int target){
    int n = nums.size();

    int duplicates = 0;

    vector<int> pos;
    vector<int> prefix (n + 1, 0);
    // prefix[0] is - 1 index
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i];
        if (nums[i] == target)
        {
            pos.push_back(i);
            prefix[i + 1]++;
        }
    }

    int ans = pos.size();
    if (ans == 0) return {0 , 0};
    

    for (int length = 2; length <= n; length++)
    {
        // index till start should be greater than equal to length

        for (int i = 0; i < pos.size(); i++)
        {
            int curr_index = pos[i];

            int nxt_idx = curr_index + length - 1;

            if (nxt_idx >= n) break;



            if (prefix[nxt_idx + 1] - prefix[curr_index + 1] + 1 > length/2 )
            {
                ans++;
                if (nums[nxt_idx] == target)
                    {
                        duplicates++;
                    }
            }
        }
    }

    duplicates += pos.size();

    return {ans , duplicates};
}


int countMajoritySubarrays(vector<int>& nums , int target){
    // first iteration store pos , start with lenght 2 till n
    // we can also store till that pos how many target elements we have
    // do prefix sum

    vector<int> right = calculateMajorityRightSide(nums , target);

    if(right[0] == 0) return 0;

    reverse(nums.begin() , nums.end());

    vector<int> left = calculateMajorityRightSide(nums , target);

    return right[0] + left[0] - right[1];
    
}

int main(){
    vector <int> nums = {1 , 1 , 1 , 1};
    int target = 1;

    cout << countMajoritySubarrays(nums , target) << endl ;
    return 0;
}