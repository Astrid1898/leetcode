//给定一个二叉树，判断它是否是高度平衡的二叉树。 
//
// 本题中，一棵高度平衡二叉树定义为： 
//
// 
// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。 
// 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：true
// 
//
// 示例 2： 
// 
// 
//输入：root = [1,2,2,3,3,null,null,4,4]
//输出：false
// 
//
// 示例 3： 
//
// 
//输入：root = []
//输出：true
// 
//
// 
//
// 提示： 
//
// 
// 树中的节点数在范围 [0, 5000] 内 
// -10⁴ <= Node.val <= 10⁴ 
// 
//
// Related Topics 树 深度优先搜索 二叉树 👍 1331 👎 0


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


//这里遍历两边去判断，第一遍求高度，第二遍判断是否平衡，相比官方答案确实更麻烦了，可以直接用-1再判断高度的同时也判断是否平衡的

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
private:
    bool flag = true;
public:
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;
        if (flag)
        {
            flag = false;
            getHeight(root);
        }
        int leftHeight, rightHeight;
        leftHeight = root->left ? root->left->val : 0;
        rightHeight = root->right ? root->right->val : 0;
        if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        return false;
    }

    void getHeight(TreeNode *root)
    {
        int childHeight = 0;
        if (root->left)
        {
            getHeight(root->left);
            childHeight = max(childHeight, root->left->val);
        }
        if (root->right)
        {
            getHeight(root->right);
            childHeight = max(childHeight, root->right->val);
        }
        root->val = childHeight + 1;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    s.isBalanced(root);

    return 0;
}