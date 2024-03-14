class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        priority_queue<int> pq;

        for(auto &it : happiness)
        {
            pq.push(it);
        }

        int count = 0;

        while(!pq.empty() && k > 0)
        {
            int a = pq.top();
            pq.pop();
            a -= count;
            if(a <= 0)
            {
                break;
            }
            count++;
            ans += a;
            k--;
        }

        return ans;
    }
};