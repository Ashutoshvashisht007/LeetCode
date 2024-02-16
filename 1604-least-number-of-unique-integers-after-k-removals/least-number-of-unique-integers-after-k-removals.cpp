class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto &it : arr)
        {
            mp[it]++;
        }

        vector<int> temp;
        for(auto &it : mp)
        {
            temp.push_back(it.second);
        }

        sort(temp.begin(),temp.end());
        int ans = temp.size();
        for(int i=0;i<temp.size();i++)
        {
            if(k <= 0 || k < temp[i])
            {
                break;
            }
            if(k >= temp[i])
            {
                k -= temp[i];
                ans--;
            }
        }


        return ans;
    }
};