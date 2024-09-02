class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        vector<vector<int>> chess(8,vector<int>(8));
        bool flag = true;
        for(int i=0;i<8;i++){
            int temp;
            if(flag){
                temp = 1;
            }
            else
            {
                temp = 0;
            }
            for(int j=0;j<8;j++)
            {
                chess[i][j] = temp;
                temp = !temp;
            }
            flag = !flag;
        }

        int col1 = coordinate1[0] - 'a';
        int row1 = (coordinate1[1] - '0') - 1;
        int col2 = coordinate2[0] - 'a';
        int row2 = (coordinate2[1] - '0') - 1;

        if(chess[row1][col1] == chess[row2][col2]){
            return true;
        }

        return false;
    }
};