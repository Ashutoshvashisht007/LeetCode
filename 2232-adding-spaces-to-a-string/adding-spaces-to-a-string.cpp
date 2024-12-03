class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int j = 0,idx = 0;
        string ans = "";
        for(int i=0;i<s.size();i++)
        {
            if(j < spaces.size()){
                if(idx == spaces[j]){
                    ans.push_back(' ');
                    j++;
                    cout<<idx<<" "<<s[i]<<endl;
                }
            }
            idx++;
            ans.push_back(s[i]);
        }

        return ans;
    }
};