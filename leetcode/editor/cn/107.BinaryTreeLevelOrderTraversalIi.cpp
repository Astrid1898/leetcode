//给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历） 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：[[15,7],[9,20],[3]]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：[[1]]
// 
//
// 示例 3： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [0, 2000] 内 
// -1000 <= Node.val <= 1000 
// 
//
// Related Topics 树 广度优先搜索 二叉树 👍 685 👎 0


#include<bits/stdc++.h>

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


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        ans.emplace(ans.begin(), 1, root->val);
        int level_cnt = 0;
        TreeNode *tmp;
        while (!q.empty())
        {
            level_cnt = q.size();
            vector<int> levelVal;
            for (int i = 0; i < level_cnt; i++)
            {
                tmp = q.front();
                q.pop();
                if (tmp->left)
                {
                    q.push(tmp->left);
                    levelVal.push_back(tmp->left->val);
                }
                if (tmp->right)
                {
                    q.push(tmp->right);
                    levelVal.push_back(tmp->right->val);
                }
            }
            level_cnt = 0;
            if (!levelVal.empty())
                ans.emplace(ans.begin(), levelVal);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;

    return 0;
}