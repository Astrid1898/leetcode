//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并
//返回其根节点。 
//
// 
//
// 示例 1: 
// 
// 
//输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//输出: [3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//输入: preorder = [-1], inorder = [-1]
//输出: [-1]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= preorder.length <= 3000 
// inorder.length == preorder.length 
// -3000 <= preorder[i], inorder[i] <= 3000 
// preorder 和 inorder 均 无重复 元素 
// inorder 均出现在 preorder 
// preorder 保证 为二叉树的前序遍历序列 
// inorder 保证 为二叉树的中序遍历序列 
// 
//
// Related Topics 树 数组 哈希表 分治 二叉树 👍 1971 👎 0

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#include<bits/stdc++.h>

using namespace std;

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode *root = new TreeNode(preorder[0]);
        if (preorder.size() == 1)
            return root;
        int idx = 0;
        for (; idx < inorder.size(); idx++)
        {
            if (root->val != inorder[idx])
                continue;
            else
                break;
        }
        root->left = getChild(1, idx, 0, idx - 1, preorder, inorder);
        root->right = getChild(idx + 1, preorder.size() - 1, idx + 1, inorder.size() - 1, preorder, inorder);
        return root;
    }

    TreeNode *getChild(int preorderBegin, int preorderEnd, int inorderBegin, int inorderEnd, vector<int> &preorder,
                       vector<int> &inorder)
    {
        if (preorderBegin == preorderEnd)
        {
            return new TreeNode(preorder[preorderBegin]);
        }
        else if (preorderEnd < preorderBegin || inorderEnd < inorderBegin)
            return nullptr;


        TreeNode *root = new TreeNode(preorder[preorderBegin]);
        int idx = inorderBegin;
        for (; idx < inorder.size(); idx++)
        {
            if (root->val != inorder[idx])
                continue;
            else
                break;
        }
        root->left = getChild(preorderBegin + 1, preorderBegin + idx - inorderBegin, inorderBegin, idx - 1, preorder,
                              inorder);
        root->right = getChild(preorderBegin + idx - inorderBegin + 1, preorderEnd, idx + 1, inorderEnd, preorder,
                               inorder);

        return root;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> preorder{1, 2, 3};
    vector<int> inorder{3, 2, 1};
    TreeNode *root = s.buildTree(preorder, inorder);
    return 0;
}