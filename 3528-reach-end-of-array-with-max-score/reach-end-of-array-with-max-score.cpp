class Solution {
public:

    long long findMaximumScore(vector<int>& nums) {
        
        int n = nums.size();
        long long i = 0, j = 1, ans = 0;

        while(i < n && j < n){
            while(j < n && nums[i] > nums[j]){
                j++;
            }
            if(i < j && j == n){
                ans += (j - 1 - i)*nums[i];
                break;
            }
            ans += (j - i)*nums[i];
            i = j, j++;
        }

        return ans;

    }
};