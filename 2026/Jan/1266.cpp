#include <bits/stdc++.h>
using namespace std;


int timeBetweenTwoPoints(vector<int> & a , vector<int>& b){
    int x1 = a[0] , y1 = a[1];
    int x2 = b[0] , y2 = b[1];

    return min(abs(x2 - x1) , abs(y2 - y1)) + abs(abs(x2 - x1) - abs(y2 - y1)); 
}
int minTimeToVisitAllPoints(vector<vector<int>> & points){
    int time = 0;
    int n = points.size();

    for (int i = 0; i < n - 1; i++)
    {
        time += timeBetweenTwoPoints(points[i] , points[i + 1]);
    }
    
    return time;
}

int main(){
    vector<vector<int>> points = {{3 , 2} , {-2 , 2}};

    cout << minTimeToVisitAllPoints(points);

    return 0;
}