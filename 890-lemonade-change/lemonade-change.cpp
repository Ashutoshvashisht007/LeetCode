class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        if(bills[0] != 5){
            return false;
        }
        for(auto &it : bills){
            if(it == 5){
                five++;
            }
            else if(it == 10){
                if(five > 0){
                    five--;
                    ten++;
                }
                else{
                    return false;
                }
            }
            else{
                if(ten > 0 && five > 0){
                    ten--;
                    five--;
                }
                else if(five > 2){
                    five -= 3;
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
};