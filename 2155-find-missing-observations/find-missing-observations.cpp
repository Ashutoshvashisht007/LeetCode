class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        // 3 + 4 = 7
        // 7*3 = 21
        // 1+5+6 = 12
        //21 - 12 = 9
        //

        int size = rolls.size();
        int m = n + size;
        int total = m*mean;
        int rolls_sum = 0;

        for(auto &it : rolls){
            rolls_sum += it;
        }

        int rem = total - rolls_sum;
        cout<<rem<<endl;
        if(rem < n || rem > 6*n){
            return {};
        }

        int distribute = rem / n;
        rem %= n;
        vector<int> ans(n,distribute);
        for(int i=0;i<rem;i++){
            ans[i]++;
        }

        return ans;

    }
};