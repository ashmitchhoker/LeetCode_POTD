#include <bits/stdc++.h>
using namespace std;

vector<int> arrayRankTransform(vector<int> & arr){
    // store index also 

    vector<int> sorted = arr;

    sort(sorted.begin() , sorted.end());

    unordered_map<int , int> rank;
    int current_rank = 1;

    for (int num : sorted)
    {
        if(!rank.count(num)){
            rank[num] = current_rank++;
        }
    }

    for (int &num : arr)
    {
        num = rank[num];
    }
    
    return arr;
}

int main() {

    vector<int> arr = {37,12,28,9,100,56,80,5,12};

    vector<int> result = arrayRankTransform(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}