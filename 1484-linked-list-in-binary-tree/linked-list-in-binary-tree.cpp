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

    bool preorder(ListNode* head,TreeNode* root){
        if(!head){
            return true;
        }
        if(!root){
            return false;
        }
        bool left = false, right = false;

        if(head->val == root->val){
            left = preorder(head->next,root->left);
            right = preorder(head->next,root->right);
        }

        return left || right;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root){
            return false;
        }
        bool pre = preorder(head,root);
        bool left = isSubPath(head,root->left);
        bool right = isSubPath(head,root->right);
        return pre || left || right;
    }
};