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



int dfs(TreeNode* root , unordered_map<TreeNode* , vector<int>> & depth ,  int d){
    if (!root)
    {
        return d - 1;
    }

    depth[root].push_back(dfs(root->left , depth , d + 1));
    depth[root].push_back(dfs(root->right , depth , d + 1));

    return max(depth[root][0] , depth[root][1]);
}


TreeNode* subtreeWithAllDeepest(TreeNode* root){
    unordered_map<TreeNode* , vector<int>> depth;

    dfs(root , depth , 1);

    TreeNode* temp = root;

    while(true){
        if (depth[temp][0] == depth[temp][1])
        {
            return temp;
        }

        if (depth[temp][0] > depth[temp][1])
        {
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }

    return temp;
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
    vector<int> vals = {1};
    TreeNode * root = build(vals);

    cout << subtreeWithAllDeepest(root)->val << endl;

    return 0;
}