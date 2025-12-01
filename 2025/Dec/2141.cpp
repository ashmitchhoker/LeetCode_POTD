#include <bits/stdc++.h>
using namespace std;


bool check(long long int time , int n , vector<int> & batteries){
    long long int contributions = 0;

    for(int i = 0 ; i < batteries.size() ; i++){
        contributions += min(1LL * batteries[i] , time);
    }
    if(contributions >= n * time) return true;
    return false;
}

long long maxRunTime(int n, vector<int>& batteries) {
    int b = batteries.size();

    // total energy required will be n * time 
    // maximum we can take from battery is min(battery[i] , time)

    long long int low = 0;
    long long int high = 1e14;
    long long int ans = 0;

    while(low <= high){
        long long int mid = (high + low)/2;
        if(check(mid , n , batteries)){
            low = mid + 1;
            ans = max(mid , ans);
        }
        else{
            high = mid - 1;
        }
    }

    return ans;
}

int main(){
    int n = 2;
    vector<int> batteries = {1 , 1 , 1 , 1};
    cout << maxRunTime(n , batteries);
    return 0;
}