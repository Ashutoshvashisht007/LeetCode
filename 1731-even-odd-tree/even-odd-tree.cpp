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
    bool isEvenOddTree(TreeNode* root) {
        if(root->val % 2 == 0)
        {
            return false;
        }
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        while(!q.empty())
        {
            int size = q.size();
            int last;
            if(lvl % 2 == 0)
            {
                last = INT_MIN;
            }
            else
            {
                last = INT_MAX;
            }
            while(size--)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(lvl % 2 == 0)
                {
                    if(last >= temp->val || temp->val % 2 == 0)
                    {
                        return false;
                    }
                }
                else
                {
                    if(last <= temp->val || temp->val % 2 == 1)
                    {
                        return false;
                    }
                }
                last = temp->val;
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            lvl++;
        }
        return true;
    }
};