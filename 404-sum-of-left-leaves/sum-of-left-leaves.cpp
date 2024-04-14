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

    bool isLeaf(TreeNode* root)
    {
        if(root->left || root->right)
        {
            return false;
        }

        return true;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*,bool>> q;
        q.push({root,false});

        while(!q.empty())
        {
            TreeNode* temp = q.front().first;
            bool flag = q.front().second;
            q.pop();

            if(isLeaf(temp) && flag)
            {
                ans += temp->val;
                continue;
            }
            if(temp->left)
            {
                q.push({temp->left,true});
            }
            if(temp->right)
            {
                q.push({temp->right,false});
            }
        }

        return ans;
    }
};