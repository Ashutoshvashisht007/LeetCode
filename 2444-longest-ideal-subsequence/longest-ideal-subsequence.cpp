class Solution {
public:

    int recur(int idx,int prev,int k,string &s,vector<vector<int>> &dp)
    {
        if(s.size() == idx)
        {
            return 0;
        }

        if(dp[idx][prev + 1] != -1){
            return dp[idx][prev + 1];
        }

        int take = 0;

        if(prev == -1){
            take = recur(idx + 1,s[idx] - 'a',k,s,dp) + 1;
        }
        else
        {
            int value = s[idx] - 'a';
            if(abs(prev - value) <= k)
            {
                take = recur(idx + 1,value,k,s,dp) + 1;
            }
        }

        int not_take = recur(idx + 1,prev,k,s,dp);

        return dp[idx][prev + 1] = max(take,not_take);
    }

    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.size() + 1,vector<int>(30,-1));
        return recur(0,-1,k,s,dp);
    }
};