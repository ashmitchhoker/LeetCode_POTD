#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxLevelSum(TreeNode* root){
    if (!root) return 0;
    queue<TreeNode*> q;

    q.push(root);
    int level = 1;
    int ans = 0;

    long long maxi = LLONG_MIN;

    while (!q.empty())
    {
        long long tempSum = 0;
        int n = q.size();
        
        for (int i = 0; i < n; i++)
        {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }

            tempSum += curr->val;
        }
        
        if (tempSum > maxi)
        {
            ans = level;
            maxi = tempSum;
        }
    
        level++;
    }
    return ans;
}

TreeNode* build(const vector<int> & vals){
    if (vals.empty() || vals[0] == INT_MIN) return nullptr;

    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;

    q.push(root);
    int i = 1;

    while (!q.empty() && i < vals.size())
    {
        TreeNode* curr = q.front();
        q.pop();

        if (i < vals.size() && vals[i] != INT_MIN)
        {
            curr->left = new TreeNode(vals[i]);
            q.push(curr->left);
        }
        i++;
        if (i < vals.size() && vals[i] != INT_MIN)
        {
            curr->right = new TreeNode(vals[i]);
            q.push(curr->right);
        }
        i++;
    }
    

    return root;
}

int main(){
    vector<int> vals = {989,INT_MIN,10250,98693,-89388,INT_MIN , INT_MIN , INT_MIN ,-32127};

    TreeNode* root = build(vals);

    cout << maxLevelSum(root);

    return 0;
}