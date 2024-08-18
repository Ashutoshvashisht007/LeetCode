class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1,-1);

        for(int i=0;i<n - k + 1;i++){
            int mx = nums[i];
            for(int j=i+1;j<i+k && j < n;j++){
                if((nums[j - 1] >= nums[j]) || (nums[j] - nums[j - 1] > 1)){
                    mx = -1;
                    break;
                }
                mx = max(mx,nums[j]);
            }
            ans[i] = mx;
        }

        return ans;
    }
};