#include <bits/stdc++.h>
using namespace std;

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    // operations could be decrease to smallest number
    // rearrange
    // what is maximum after this
    // first should be 1 , absolute between adjacent is max 1

    // range of maximum is (1 , max)

    // binary search

    int n = arr.size();

    // sorting n logn
    sort(arr.begin() , arr.end());

    arr[0] = 1;
    

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[i - 1] > 1)
        {
            arr[i] = arr[i - 1] + 1;
        }
        
    }

    return arr[n - 1];
    
}

int main(){
    vector<int> arr = {2 , 2 , 1 , 2 , 1};

    cout << maximumElementAfterDecrementingAndRearranging(arr);

    return 0;
}