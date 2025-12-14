#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int numberOfWays(string corridor){
    int n = corridor.size();

    vector<int> seats;
    for(int i = 0 ; i < n ; i++){
        if(corridor[i] == 'S') seats.push_back(i);
    }

    if(seats.size() % 2 == 1) return 0;
    if (seats.size() == 2)
    {
        return 1;
    }
    
    long ans = 1;
    if(seats.empty()) return 0;
    for(int i = 0 ; i < seats.size() - 2 ; i += 2){
        int gap = (seats[i + 2] - seats[i + 1]) % mod;
        ans = (ans * gap) % mod;
        ans = ans % mod;
    }

    return (int)ans;
}


int main(){
    string corridor = "S";
    cout << numberOfWays(corridor);
    return 0;
}