class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string,int> mp;
        for(auto &it : bannedWords){
            mp[it]++;
        }

        int count = 0;
    
        for(auto &it : message){
            if(mp.find(it) != mp.end()){
                count++;
            }
            if(count >= 2){
                return true;
            }
        }

        return false;
    }
};