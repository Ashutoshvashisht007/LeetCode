class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int ans = 0;
        vector<int> subArray;
        for(int i=0;i<n;i++)
        {
            int sum = 0;
            for(int j=i;j<n;j++)
            {
                sum += nums[j];
                subArray.push_back(sum);
            }
        }

        sort(subArray.begin(),subArray.end());

        for(int i=left-1;i<=right-1;i++){
            ans = (ans + subArray[i]) % 1000000007;
        }

        return ans;
    }
};