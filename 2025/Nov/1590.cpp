#include <bits/stdc++.h>
#include <map>
using namespace std;


int minSubarray(vector<int> & nums , int p){
    int n = nums.size();
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += nums[i];
        sum %= p;
    }
    int remain = sum;
    if(sum == 0) return 0;

    int ans = n;
    unordered_map<int , int> remainders; // remainder its last occurence
    remainders[0] = -1;
    int currSum = 0;

    for(int i = 0 ; i < n ; i++){
        currSum += nums[i];
        currSum %= p;

        int prefix = (currSum - remain + p) % p;
        if(remainders.count(prefix)){
            ans = min(ans , i - remainders[prefix]);
        }
        remainders[currSum] = i;
    }

    if(ans == n) return -1;
    return ans;
}
// int minSubarray(vector<int> &nums, int p)
// {
//     int n = nums.size();

//     vector<int> prefix(n + 1, 0);
//     for (int i = 0; i < n; i++)
//     {
//         prefix[i + 1] = prefix[i] + nums[i];
//     }

//     int ans = INT_MAX;
//     if(prefix[n] % p == 0) return 0;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = i; j > 0; j--)
//         {
//             cout << i << " " << (prefix[n] - (prefix[i] - prefix[j - 1])) << endl;
//             long long sum = prefix[n] - (prefix[i] - prefix[j - 1]);
//             if (sum != 0 && sum % p == 0)
//             {
//                 ans = min(ans, i - j + 1);
//             }
//         }
//     }

//     if (ans == INT_MAX)
//         return -1;
//     return ans;
// }

int main()
{
    vector<int> nums = {1 , 2 , 3};
    int p = 7;

    cout << minSubarray(nums, p);

    return 0;
}