/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Step 1: Move all non-zero elements to the front
        int nonZeroPos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[nonZeroPos] = nums[i];
                nonZeroPos++;
            }
        }
        
        // Step 2: Fill the rest with zeroes
        for (int i = nonZeroPos; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
// @lc code=end

