class Solution {
public:
    string getSmallestString(string s, int k) {
        if(k == 0)
        {
            return s;
        }
        for(auto &it : s)
        {
            cout<<(it - 'a')<<" "<<('z' - it + 1)<<endl;
            int diff = min(it - 'a','z' - it + 1);
            if(k >= diff)
            {
                k -= diff;
                it = 'a';
            }
            else
            {
                it = it - k;
                k = 0;
            }
        }

        return s;
    }
};