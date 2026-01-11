#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> s;
    int maxarea = 0;
    for(int i = 0 ; i <= n ; i ++){
        int curr = (i == n) ? 0 : heights[i];
        while(!s.empty() && curr < heights[s.top()]){
            int top = s.top();
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            int area = heights[top] * width;
            maxarea = max(maxarea, area);
        }
        s.push(i);
    }
    return maxarea;
}

int maximalRectangle(vector<vector<char>> & matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> cols(m , 0);
    int ans = 0;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
            {
                cols[j] += 1;
            }
            else{
                cols[j] = 0;
            }
        }
        ans = max(ans , largestRectangleArea(cols));
    }
    return ans;
}

int main(){
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << maximalRectangle(matrix);
    return 0;
}