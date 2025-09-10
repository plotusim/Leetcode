/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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

    TreeNode* buildBinaryTree(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd){
        if(preStart > preEnd) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int root_inorder_idx = HashMap[preorder[preStart]];
        int preorder_left = preStart + root_inorder_idx - inStart;
        root->left = buildBinaryTree(preorder,preStart+1,preorder_left,inorder,inStart,root_inorder_idx-1);
        root->right = buildBinaryTree(preorder,preorder_left+1,preEnd,inorder,root_inorder_idx+1,inEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //construct hashmap
        for(int i=0;i<inorder.size();i++){
            HashMap.insert(make_pair(inorder[i],i));
        }
        return buildBinaryTree(preorder,0,preorder.size()-1,
                        inorder,0,inorder.size()-1);
    }
};
// @lc code=end

