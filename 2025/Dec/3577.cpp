#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int countPermutations(vector<int>& complexity){
    int n = complexity.size();

    for(int i = 1 ; i < n ; i++){
        if(complexity[i] <= complexity[0]) return 0;
    }

    long ans = 1;

    for(int i = 1 ; i <= n - 1 ; i++){
        ans *= i;
        ans %= mod;
    }

    return int(ans);
    
}


int main(){
    vector<int> complexity = {3 , 3 , 4 , 4 , 4};

    cout << countPermutations(complexity);

    return 0;
}