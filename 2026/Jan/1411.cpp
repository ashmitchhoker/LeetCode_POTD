#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

// void recurse(int left , int & ans , int type , long long carry){
//     // type 0 for 3 type , 1 for 2 type

//     if (left == 0)
//     {   
//         carry %= mod;
//         ans += (int)carry;
//         ans %= mod;
//         return;
//     }
    
//     if (type == 0)
//     {
//         recurse(left - 1 , ans , 0 , (carry * 2) % mod );
//         recurse(left - 1 , ans , 1 , (carry * 2) % mod );
//     }

//     else{
//         recurse(left - 1 , ans , 0 , (carry * 2) % mod);
//         recurse(left - 1 , ans , 1 , (carry * 3) % mod);
//     }
// }
int numOfWays(int n){
    long long A = 6 , B = 6;

    for (int i = 2; i <= n; i++)
    {
        long long newA = (A * 2 + B * 2) % mod;
        long long newB = (A * 2 + B * 3) % mod;

        A = newA;
        B = newB;
    }
    

    return (int)(A + B) % mod;
}

int main(){
    int n = 3000;

    cout << numOfWays(n) << endl;

    return 0;
}