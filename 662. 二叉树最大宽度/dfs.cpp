#include "../stdc++.h"
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using ULL = unsigned long long;

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        // <当前层数， 当前层最左边的编号>
        unordered_map<int, ULL> levelMin;
        function<ULL(TreeNode *, int, ULL)> dfs = [&](TreeNode *node, int depth, ULL index) -> ULL {
            if (node == nullptr) {
                return 0LL;
            }
            // 如果当前访问到的节点是当前层最左边的节点
            if (!levelMin.count(depth)) {
                // 每一层最先访问到的节点会是最左边的节点，即每一层编号的最小值
                levelMin[depth] = index;
            }
            return max(
                {
                    // 当前节点的宽度
                    index - levelMin[depth] + 1LL,
                    // 下一层左孩子
                    dfs(node->left, depth + 1, index * 2),
                    // 下一层右孩子
                    dfs(node->right, depth + 1, index * 2 + 1)
                });
        };
        return dfs(root, 1, 1LL);
    }
};