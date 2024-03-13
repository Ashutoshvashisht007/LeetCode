class Solution {
public:
    int pivotInteger(int n) {
        vector<int> prefix(n+1,0);
        vector<int> suffix(n+1,0);
        prefix[1] = 1;
        for(int i=2;i<=n;i++)
        {
            prefix[i] = prefix[i - 1] + i;
        }
        suffix[n] = n;
        for(int i = n - 1;i>0;i--)
        {
            suffix[i] = suffix[i + 1] + i;
        }

        for(int i=1;i<=n;i++)
        {
            if(suffix[i] == prefix[i])
            {
                return i;
            }
        }

        return -1;
    }
};