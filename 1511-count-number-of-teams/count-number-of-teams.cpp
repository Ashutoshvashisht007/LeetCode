class Solution {
public:

    int recur1(int idx,vector<int> &rating,int count,int prev,vector<vector<vector<int>>> &dp){
        // base
        if(count == 3){
            return 1;
        }
        if(idx == rating.size()){
            return 0;
        }

        if(dp[idx][count][prev+1] != -1){
            return dp[idx][count][prev+1];
        }

        // logic

        int take = 0, not_take = 0;

        not_take = recur1(idx + 1,rating,count,prev,dp);

        if((prev == -1) || (rating[prev] < rating[idx])){
            take = recur1(idx + 1,rating,count + 1,idx,dp);
        }

        return dp[idx][count][prev+1] = not_take + take;
    }

    int recur2(int idx,vector<int> &rating,int count,int prev,vector<vector<vector<int>>> &dp){
        // base
        if(count == 3){
            return 1;
        }
        if(idx == rating.size()){
            return 0;
        }

        if(dp[idx][count][prev+1] != -1){
            return dp[idx][count][prev+1];
        }

        // logic

        int take = 0, not_take = 0;

        not_take = recur2(idx + 1,rating,count,prev,dp);

        if((prev == -1) || (rating[prev] > rating[idx])){
            take = recur2(idx + 1,rating,count + 1,idx,dp);
        }

        return dp[idx][count][prev+1] = not_take + take;
    }

    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (5,vector<int>(n+1,-1)));
        int a = recur1(0,rating,0,-1,dp);
        dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(5, vector<int>(n+1, -1)));
        int b = recur2(0,rating,0,-1,dp);

        return a + b;
    }
};