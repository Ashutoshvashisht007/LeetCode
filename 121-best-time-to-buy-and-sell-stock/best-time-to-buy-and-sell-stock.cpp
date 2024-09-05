class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mn = prices[0];
        int mx = prices[0], ans = 0;

        for(int i=0;i<n;i++){
            if(prices[i] < mn){
                mn = prices[i];
                mx = INT_MIN    ;
            }
            mx = max(mx,prices[i]);
            ans = max(ans,mx - mn);
        }

        return ans;
    }
};