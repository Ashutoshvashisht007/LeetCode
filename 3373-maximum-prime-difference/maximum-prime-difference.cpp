class Solution {
public:

    int findMax(vector<int>& nums)
    {
        int mx = 0;
        for(auto &it : nums)
        {
            mx = max(mx,it);
        }

        return mx;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        int largestVal = findMax(nums);
        vector<bool> prime(largestVal+1,true);
        prime[1] = false;

        for(int i=2;i*i <= largestVal;i++)
        {
            if(prime[i])
            {
                for (int j = i * i; j <= largestVal; j += i)
                {
                    prime[j] = false;
                }
            }
        }
        int mn = INT_MAX, mx = INT_MIN;

        for(int i = 0;i < n;i++)
        {
            if(prime[nums[i]])
            {
                mn = min(mn,i);
                mx = max(mx,i);
            }
        }
        // if(mx )
        return mx - mn;
    }
};