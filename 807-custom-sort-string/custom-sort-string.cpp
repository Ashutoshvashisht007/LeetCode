class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,vector<int>> mp;

        for(int i=0;i<s.size();i++)
        {
            mp[s[i]].push_back(i);
        }
        string ans;
        vector<int> vis(s.size(),0);
        for(int i=0;i<order.size();i++)
        {
            if(mp.find(order[i]) != mp.end())
            {
                for(auto &it : mp[order[i]])
                {
                    ans.push_back(order[i]);
                    vis[it] = 1;
                }
            }
        }
        for(int i=0;i<s.size();i++)
        {
            if(!vis[i])
            {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};