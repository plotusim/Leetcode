/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // if (list1.val ==0 && list1->next == nullptr){
        //     return list2;
        // }
        // if (list2.val ==0 && list2->next == nullptr){
        //     return list1;
        // }

        // ListNode* head = ListNode();
        // head->next = ListNode();
        // ListNode* vis = head->next;

        // while(true){
        //     if (list1.val < list2.val){
        //         vis.val = list1.val;
        //         list1 = list1->next;
        //         ListNode* newnode = ListNode();
        //         vis->next = newnode;
        //         vis = vis->next;
        //     };
        //     else{
        //         vis.val = list2.val;
        //         list2 = list2->next;
        //         ListNode* newnode = ListNode();
        //         vis->next = newnode;
        //         vis = vis->next;
        //     }

        //     if(list1 == nullptr){
        //         vis = list2;
        //         return head->next;
        //     }
        //     else{
        //         vis = list1;
        //         return head->next;
        //     }
        // }

        if (!list1){
            return list2;
        }
        if (!list2){
            return list1;
        }

        ListNode* head = new ListNode(0);
        ListNode* vis = head;

        while(true){
            if (list1->val < list2->val){
                ListNode* newnode = new ListNode(list1->val);
                vis->next = newnode;
                vis = vis->next;
                list1 = list1->next;
            }
            else{
                ListNode* newnode = new ListNode(list2->val);
                vis->next = newnode;
                vis = vis->next;
                list2 = list2->next;
            }

            if(list1 == nullptr){
                vis->next = list2;
                return head->next;
            }
            if(list2 == nullptr){
                vis->next = list1;
                return head->next;
            }
        }
    }
};
// @lc code=end

