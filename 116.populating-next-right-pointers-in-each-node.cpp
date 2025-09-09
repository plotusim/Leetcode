/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void traverse(Node* n1,Node* n2){
        if(n1 == NULL || n2 == NULL) return;
        
        n1->next = n2;
        traverse(n1->left,n1->right);
        traverse(n2->left,n2->right);
        traverse(n1->right,n2->left);
        
    }

    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        traverse(root->left,root->right);
        return root;
    }
};
// @lc code=end

