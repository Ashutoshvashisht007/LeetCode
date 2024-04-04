class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int size = st.size();
            ans = max(ans,size);
            if(s[i] == '(')
            {
                st.push('(');
            }
            else if(s[i] == ')')
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
        }
        
        return ans;
    }
};