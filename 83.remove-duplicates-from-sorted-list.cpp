/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr){
            while(fast!= nullptr && fast->val ==slow->val){
                fast=fast->next;
            }
            if(slow->next != fast){
                ListNode* del = slow->next;
                slow->next = fast;
                delete del;
            }
            slow = slow->next;
        }
        return head;
    }
};
// @lc code=end

