class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,bool>> q;
        for(int i=0;i<tickets.size();i++)
        {
            if(i == k)
            {
                q.push({tickets[i],true});
            }
            else
            {
                q.push({tickets[i],false});
            }
        }
        int ans = 0;

        while(!q.empty())
        {
            int num = q.front().first;
            bool flag = q.front().second;
            q.pop();
            num -= 1;
            ans++;
            if(num == 0 && flag == true)
            {
                break;
            }
            if(num > 0)
            {
                q.push({num,flag});
            }
        }

        return ans;
    }
};