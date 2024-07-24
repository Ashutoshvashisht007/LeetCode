class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            int num = nums[i];
            int temp = num == 0 ? mapping[0] : 0;
            int place = 1;
            while(num > 0){
                int rem = num % 10;
                temp = temp + (place *  mapping[rem]);
                num /= 10;
                place *= 10;
            }
            v.push_back({temp,i});
        }

        sort(v.begin(),v.end());
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(nums[v[i].second]);
        }
        return ans;
    }
};