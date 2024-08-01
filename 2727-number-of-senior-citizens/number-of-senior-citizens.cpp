class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto &it:details){
            string temp;
            for(int i=11;i<=12;i++)
            {
                temp += it[i];
            }
            int age = stoi(temp);
            if(age > 60)
            {
                ans++;
            }
        }

        return ans;
    }
};