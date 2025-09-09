/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
    // TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    //     if(nums.size() == 0) return nullptr;

    //     // max element
    //     int max = -1;
    //     int max_id = -1;
    //     for(int i=0;i<nums.size();i++){
    //         if(nums[i]>max){
    //             max = nums[i];
    //             max_id = i;
    //         }
    //     } 

    //     // constructMaximumBinaryTree
    //     TreeNode* root = new TreeNode(max);
    //     vector<int> left(nums.begin(), nums.begin() + max_id);
    //     vector<int> right(nums.begin() + max_id + 1, nums.end());
    //     root->left = constructMaximumBinaryTree(left);
    //     root->right = constructMaximumBinaryTree(right);
    //     return root;
    // }

    TreeNode* build(vector<int>& nums, int l, int r) {
        if(l > r) return nullptr;

        int max_id = l;
        for(int i = l; i <= r; i++) {
            if(nums[i] > nums[max_id]) max_id = i;
        }

        TreeNode* root = new TreeNode(nums[max_id]);
        root->left = build(nums, l, max_id - 1);
        root->right = build(nums, max_id + 1, r);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }

};
// @lc code=end

