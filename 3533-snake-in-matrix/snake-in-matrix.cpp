class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int row = 0, col = 0;
        vector<vector<int>> mat(n,vector<int>(n,0));
        int sum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = sum;
                sum++;
            }
        }

        for(auto &it : commands){
            if(it == "RIGHT"){
                col++;
            }
            else if(it == "DOWN"){
                row++;
            }
            else if(it == "LEFT"){
                col--;
            }
            else if(it == "UP"){
                row--;
            }
        }

        return mat[row][col];
    }
};