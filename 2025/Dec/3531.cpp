#include <bits/stdc++.h>
using namespace std;


int countCoveredBuildings(int n , vector<vector<int>> & buildings){
    unordered_map<int , pair<int , int>> rows;
    unordered_map<int , pair<int , int>> cols;


    for (vector<int>& building : buildings)
    {
        int row = building[0] , col = building[1];
        if(!rows.count(row)) rows[row] = {INT_MIN , INT_MAX};
        if(!cols.count(col)) cols[col] = {INT_MIN , INT_MAX};
        rows[row] = {max(rows[row].first , col) , min(rows[row].second , col)};
        cols[col] = {max(cols[col].first , row) , min(cols[col].second , row)};
    }


    int ans = 0;


    for(vector<int> & building : buildings){
        int row = building[0] , col = building[1];
        if((rows[row].first > col && rows[row].second < col) && (cols[col].first > row && cols[col].second < row)) ans++;
    }

    // cout << rows[2].first << " " << cols[2].first << endl;
    // cout << rows[2].second << " " << cols[2].second << endl;

    return ans;
}


int main(){
    int n = 3;
    vector<vector<int>> buildings = {{1 , 3} , {3 , 2} , {3 , 3} , {3 , 5} , {5 , 3}};

    cout << countCoveredBuildings(n , buildings);

    return 0;
}