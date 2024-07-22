class Solution {
public:
    bool doesAliceWin(string s) {
        int n = s.size();

        int vowels = 0;
        for(auto &it : s){
            if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u'){
                vowels++;
            }
        }

        if(vowels % 2 != 0){
            return true;
        }
        if(vowels == 0){
            return false;
        }
        
        return true;
    }
};