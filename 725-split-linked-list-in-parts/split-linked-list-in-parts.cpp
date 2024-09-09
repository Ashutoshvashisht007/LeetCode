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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        int div = count / k;
        int rem = count % k;
        cout<<rem<<endl;
        vector<ListNode*> ans(k,NULL);
        temp = head;
        int j = 0;
        while(temp){
            ans[j] = temp;
            ListNode* prev = NULL;
            for(int i=0;i<div + (rem > 0) && temp != NULL;i++){
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            j++;
            rem--;
        }

        return ans;
    }
};