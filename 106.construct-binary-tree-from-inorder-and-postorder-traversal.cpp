/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */

// @lc code=start
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
class Solution {
public:
    unordered_map<int,int> HashMap;

    TreeNode* buildBinaryTree(vector<int>& inorder,int inStart,int inEnd, vector<int>& postorder,int postStart,int postEnd){
        if(inStart > inEnd || postStart>postEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int root_in_inorder = HashMap[postorder[postEnd]];
        int left_postorder = postStart+root_in_inorder-inStart-1; 
        //int left_postorder = postStart+root_in_inorder-inStart; 错误 
        root->left = buildBinaryTree(inorder,inStart,root_in_inorder-1,postorder,postStart,left_postorder);
        root->right = buildBinaryTree(inorder,root_in_inorder+1,inEnd,postorder,left_postorder+1,postEnd-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            HashMap.insert(make_pair(inorder[i],i));
        }
        return buildBinaryTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
};
// @lc code=end

