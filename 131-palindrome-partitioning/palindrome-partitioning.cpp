class Solution {
public:
     bool isPal(string &s,int left,int right)
    {
        while(left < right)
        {
            if(s[left++] != s[right--])
            {
                return false;
            }
        }

        return true;
    }

    void recur(int idx,string &s,vector<vector<string>> &ans,vector<string> &v)
    {
        if(idx == s.size())
        {
            ans.push_back(v);
            return;
        }

        for(int i=idx;i<s.size();i++)
        {
            if(isPal(s,idx,i))
            {
                v.push_back(s.substr(idx,i - idx + 1));
                recur(i + 1,s,ans,v);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;

        recur(0,s,ans,v);

        return ans;
    }
};