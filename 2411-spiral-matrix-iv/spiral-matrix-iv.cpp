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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int row_start = 0, col_start = 0, row_end = m - 1;
        int col_end = n - 1;
        while(head){
            for(int col = col_start;col<=col_end && head;col++){
                ans[row_start][col] = head->val;
                head = head->next;
            }
            row_start++;
            for(int row = row_start;row<=row_end && head;row++){
                ans[row][col_end] = head->val;
                head = head->next;
            }

            col_end -= 1;
            if(row_start <= row_end)
            {
                for(int col=col_end;col>=col_start && head;col--){
                    ans[row_end][col] = head->val;
                    head = head->next;
                }
                row_end--;
            }

            if(col_start <= col_end)
            {
                for(int row=row_end;row>=row_start && head;row--){
                    ans[row][col_start] = head->val;
                    head = head->next;
                }
                col_start++;
            }
        }

        return ans;
    }
};