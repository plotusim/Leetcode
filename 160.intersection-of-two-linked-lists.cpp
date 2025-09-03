/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ListNode* firstA = headA;
        // ListNode* firstB = headB;
        // while(true){
        //     if(!firstA && !firstB){return nullptr;}
        //     if(!firstA){firstA = headB;}
        //     if(!firstB){firstB = headA;}
        //     firstA = firstA->next;
        //     firstB = firstB->next;
        //     if(firstA == firstB){return firstA;}
        // }
        ListNode* firstA = headA;
        ListNode* firstB = headB;
        
        while (firstA != firstB) {
            // Advance firstA
            firstA = (firstA == nullptr) ? headB : firstA->next;
            // Advance firstB
            firstB = (firstB == nullptr) ? headA : firstB->next;
        }
        
        return firstA; // Either the intersection node or nullptr
    }
};
// @lc code=end

