class Solution {
public:

    int recur(int idx,int buy,vector<int> &prices,vector<vector<int>> &dp){
        // base

        if(idx == prices.size())
        {
            return 0;
        }
        if(dp[idx][buy] != -1)
        {
            return dp[idx][buy];
        }

        // logic

        int profit = 0;

        if(buy)
        {
            profit = max((recur(idx + 1,0,prices,dp) - prices[idx]),recur(idx + 1,1,prices,dp));
        } 
        else
        {
            profit = max((prices[idx] + recur(idx + 1,1,prices,dp)), recur(idx + 1,0,prices,dp));
        }

        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1,vector<int>(2,-1));
        return recur(0,1,prices,dp);
    }
};