class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(auto &it : nums)
        {
            pq.push(it);
        }

        int count = 0;

        while(!pq.empty())
        {
            if(pq.size() == 1)
            {
                break;
            }
            long long x = pq.top();
            if(x >= k)
            {
                break;
            }
            pq.pop();
            long long y = pq.top();
            pq.pop();

            count++;
            long long z = (min(x,y)*2) + max(x,y);
            pq.push(z);
        }

        return count;
    }
};