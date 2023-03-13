#include "../stdc++.h"
using namespace std;

class Solution {
    vector<int> vec;
public:
    // 中序遍历首先遍历左子树，然后访问根结点，最后遍历右子树
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return vec;
        inorderTraversal(root->left);
        vec.push_back(root->val);
        inorderTraversal(root->right);
        return vec;
    }
};