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

    int recur(TreeNode* root,int &ans){
        if(!root){
            return 0;
        }

        int leftCoins = recur(root->left,ans);
        int rightCoins = recur(root->right,ans);

        ans += abs(leftCoins) + abs(rightCoins);

        return (root->val - 1) + leftCoins + rightCoins;
    }

    int distributeCoins(TreeNode* root) {
        int ans = 0;
        recur(root,ans);

        return ans;
    }
};