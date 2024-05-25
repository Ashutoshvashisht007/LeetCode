class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix{0};
        for(int i=1;i<n;i++){
            int back = prefix.back();
            back += (nums[i-1] % 2 == nums[i]%2);
            prefix.push_back(back);
        }

        // for(auto it : prefix){
        //     cout<<it<<" ";
        // }

        vector<bool> ans;
        for(auto &it : queries){
            if(prefix[it[0]] == prefix[it[1]]){
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }

        return ans;
    }
};