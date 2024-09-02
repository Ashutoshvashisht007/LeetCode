class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int n = queries.size();
        priority_queue<int> pq;
        vector<int> ans;
        for(auto &it : queries){
            pq.push(abs(it[0]) + abs(it[1]));
            if(pq.size() > k){
                pq.pop();
            }
            if(pq.size() < k){
                ans.push_back(-1);
            }
            if(pq.size() == k){
                ans.push_back(pq.top());
            }
        }

        return ans;
    }
};