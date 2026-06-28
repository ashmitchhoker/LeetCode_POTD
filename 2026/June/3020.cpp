#include <bits/stdc++.h>
using namespace std;



int maximumLength(vector<int>& nums) {
    int n = nums.size();
    
    // iterating in hashset
    // number should either be 2 or greater else if 1 we will stop there or no number then there is no count and length should be odd
    // it should be square or preivous in set
    //{11 , 121 , }
    // 10 , 100 , 10000 , 100000000 (4)
    // 11 , 121 , 
    
    map<int , array<int , 2>> freq; // 0 i will keep freq , second I will keep active or not
    
    for (int i : nums)
    {
        freq[i][0]++;
        freq[i][1] = 1;
    }
    
    int ans = 0;

    if(freq.find(1) != freq.end()){
        ans = (freq[1][0] % 2 == 0) ? freq[1][0] - 1 : freq[1][0];
        freq[1][1] = 0;
    }
    for (auto i = freq.begin(); i != freq.end(); i++) {
        int temp_ans = 1;

        int start = i->first;
        int frequency = i->second[0];
        bool active = i->second[1];
        

        if(!active) continue;

        long long curr = 1LL * start * start;

        while (frequency > 1)
        {
            auto it = freq.find(curr);
            if (it == freq.end()) break;

            temp_ans++;
            frequency = it->second[0];
            it->second[1] = 0;

            curr = curr * curr;
        }

        ans = max(ans , (temp_ans-1) * 2 + 1);
    }
    

    return ans;
}

int main(){
    vector<int> nums = {1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1};
    cout << maximumLength(nums);
    return 0;
}