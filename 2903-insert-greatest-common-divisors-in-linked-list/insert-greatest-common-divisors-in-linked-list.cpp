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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;

        while(temp->next != NULL){
            int a = temp->val;
            int b = temp->next->val;
            int gcd = __gcd(a,b);
            ListNode* nxt = temp->next;
            temp->next = new ListNode(gcd);
            temp->next->next = nxt;
            temp = temp->next->next;
        }

        return head;
    }
};