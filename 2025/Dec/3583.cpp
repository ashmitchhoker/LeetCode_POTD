#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int getIndex(vector<int> pos, int ind){
    int n = pos.size();
    int left = 0;
    int right = n;

    int mid;
    while (left < right)
    {
        mid = (right - left)/2;

        if(pos[mid] > ind){
            right = mid - 1;
        }
        else{
            left = mid;
        }
        cout << "here" <<" "<< left << " " << mid << " " << right << endl;
    }
    // cout << left << endl;
    
    return left;
}
int specialTriplets(vector<int> & nums){
    int n = nums.size();
    
    unordered_map<int , vector<int>> pos;

    for (int i = 0; i < n; i++)
    {
        pos[nums[i]].push_back(i);
    }

    long ans = 0;

    for (int i = 1; i < n - 1; i++)
    {
        // cout << "here" << endl;
        int num = 2 * nums[i];
        // cout << num << endl;
        // cout << "here" << endl;
        if (pos.count(num))
        {
            int s = pos[num].size();
            
            if(pos[num][0] > i || pos[num][s - 1] < i) continue;

            // cout << "here" << endl;
            cout << "the num is " << num << endl;
            
            int ind = getIndex(pos[num] , i) + 1;
            if(num == 0){
                ans += (ind - 1) * (s - ind);
            }
            else{
                ans += (ind) * (s - ind);
            }
            ans %= mod;
        }
    }

    return (int)ans;
}

int main(){
    vector<int> nums = {0 , 1 , 0 , 0 };
    cout << specialTriplets(nums);
    return 0;
}