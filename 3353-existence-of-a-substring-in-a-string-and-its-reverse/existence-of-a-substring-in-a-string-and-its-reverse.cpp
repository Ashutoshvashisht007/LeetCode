class Solution {
public:
    bool isSubstringPresent(string s) {
        for(int i=0;i<s.size();i++)
        {
            string str = "";
            str += s[i];
            for(int j=i+1;j<s.size();j++)
            {
                str += s[j];
                string temp = str;
                reverse(temp.begin(),temp.end());
                if(temp == str)
                {
                    return true;
                }
            }
        }

        return false;
    }
};