class Solution {
public:
    int minimumDeletions(string s) {
        int b_count = 0, ans = 0;
        for(auto &it : s){
            if(it == 'a'){
                ans++;
                ans = min(ans,b_count);
            }
            else{
                b_count++;
            }
        }

        return ans;
    }
};