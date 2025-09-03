/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* vis = dummy;

        while(list1 && list2){
            if(list1->val < list2->val){
                vis->next = list1;
                list1 = list1->next;
            }
            else{
                vis->next = list2;
                list2 = list2->next;
            }
            vis = vis->next;
        }

        if(!list1){
            vis->next =list2;
        }
        if(!list2){
            vis->next=list1;
        }
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }
        if(lists.size() == 1){
            return lists[0];
        }
        ListNode* res = merge2Lists(lists[0],lists[1]);
        for(int i=2;i<lists.size();i++){
            res = merge2Lists(res,lists[i]);
        }
        return res;
    }
};
// @lc code=end

