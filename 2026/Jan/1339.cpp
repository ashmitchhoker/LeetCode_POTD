#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


long long dfs(TreeNode * root){
    if (!root)
    {
        return 0;
    }

    root->val += dfs(root->left) + dfs(root->right);

    return root->val;
}

int maxProduct(TreeNode* root){
    long long total = dfs(root);

    long long ans = 0;
    queue<TreeNode*> q;

    q.push(root);

    int n;

    while (!q.empty())
    {
        TreeNode * node = q.front();
        q.pop();
        if (!node) continue;

        long long nodeval = node->val;

        ans = max(ans , (total - nodeval) * nodeval);

        q.push(node->left);
        q.push(node->right);   
    }

    return (ans % MOD);
    
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
    vector<int> vals = {1 , 2 , 3 , 4 , 5 , 6};
    TreeNode * root = build(vals);

    cout << maxProduct(root);

    return 0;
}