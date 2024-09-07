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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mp;
        for(auto &it : nums){
            mp[it]++;
        }

        head = new ListNode(-1,head);
        ListNode* prev = head;
        while(prev->next){
            if(mp.find(prev->next->val) != mp.end()){
                ListNode* next = prev->next;
                prev->next = prev->next->next;
                delete next;
            }
            else{
                prev = prev->next;
            }
        }

        return head->next;
    }
};