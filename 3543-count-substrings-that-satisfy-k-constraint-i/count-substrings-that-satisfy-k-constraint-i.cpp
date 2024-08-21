class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int count = 0;
        int one = 0, zero = 0;
        int i = 0, j = 0;
        
        while(i < s.size()){
            if(s[i] == '0'){
                zero++;
            }
            else{
                one++;
            }

            while(zero > k && one > k){
                if(s[j] == '0'){
                    zero--;
                }
                else{
                    one--;
                }
                j++;
            }

            count += (i - j + 1);
            i++;
        }

        return count;
    }
};