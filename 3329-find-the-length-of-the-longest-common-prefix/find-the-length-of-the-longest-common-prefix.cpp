class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(auto it : arr1)
        {
            while(it > 0)
            {
                mp[it]++;
                it /= 10;
            }
        }
        int ans = 0;
        for(auto it : arr2)
        {
            while(it > 0)
            {
                if(mp.find(it) != mp.end())
                {
                    string temp = to_string(it);
                    int size = temp.size();
                    ans = max(ans,size);
                }
                it /= 10;
            }
        }

        return ans;

    }
};