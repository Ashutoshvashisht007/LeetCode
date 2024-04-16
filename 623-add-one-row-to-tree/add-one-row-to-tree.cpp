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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
         if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});

        while(!q.empty())
        {
            int lvl = q.front().second;
            TreeNode* temp = q.front().first;
            q.pop();
            if(lvl > depth)
            {
                break;
            }
            if(lvl == depth - 1)
            {
                TreeNode* leftChild = temp->left;
                TreeNode* rightChild = temp->right;
                temp->left = new TreeNode(val);
                temp->right = new TreeNode(val);
                
                temp->left->left = leftChild;
                temp->right->right = rightChild;
            }
            else
            {
                if(temp->left)
                {
                    q.push({temp->left,lvl+1});
                }
                if(temp->right)
                {
                    q.push({temp->right,lvl+1});
                }
            }
        }

        return root;
    }
};