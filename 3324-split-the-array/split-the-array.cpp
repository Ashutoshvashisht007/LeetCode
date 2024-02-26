class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int mid = nums.size();
        unordered_map<int,int> mp;
        for(auto &it: nums)
        {
            mp[it]++;
        }

        for(auto &it : mp)
        {
            if(it.second > 2)
            {
                return false;
            }
        }

        return true;
    }
};