class Solution {
public:

    long long countSubstrings(string s, char c) {
        long long ans = 0;
        for(auto &it : s)
        {
            if(it == c)
            {
                ans++;
            }
        }

        return ans * (ans + 1) / 2;
    }
};