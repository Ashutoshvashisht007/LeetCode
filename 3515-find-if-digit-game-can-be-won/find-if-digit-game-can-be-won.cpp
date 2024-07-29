class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int one_sum = 0, two_sum = 0, rest_sum = 0;

        for(auto &it : nums){
            string s = to_string(it);
            if(s.size() == 1){
                one_sum += it;
            }
            else if(s.size() == 2){
                two_sum += it;
            }
            else
            {
                rest_sum += it;
            }
        }

        return ((one_sum > (two_sum + rest_sum)) || (two_sum > (one_sum + rest_sum))) ? true : false;
    }
};