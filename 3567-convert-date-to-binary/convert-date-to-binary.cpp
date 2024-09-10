class Solution {
public:
    string convertDateToBinary(string date) {
        string st = "", ans = "";
        for(int i=0;i<date.size();i++){
            if(date[i] == '-' || i == date.size() - 1)
            {
                if(i == date.size() - 1)
                {
                    st.push_back(date[i]);
                }
                int number = stoi(st);
                int n = (int)(log2(number));
                string num = bitset<64>(number).to_string().substr(64 - n - 1);
                ans += num + "-";
                st = "";
            }
            else{
                st.push_back(date[i]);
            }
        }
        ans.pop_back();
        return ans;
    }
};