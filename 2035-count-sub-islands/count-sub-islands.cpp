class Solution {
public:
    int dr[4] = {0,1,0,-1};
    int dc[4] = {1,0,-1,0};
    void recur(vector<vector<int>> &grid1,vector<vector<int>> &grid2,int i,int j,int &flag)
    {
        int n = grid1.size(), m = grid1[0].size();
        if(grid1[i][j] == 0 && grid2[i][j] == 1){
            flag = 0;
        }
        grid2[i][j] = 0;
        for(int k=0;k<4;k++)
        {
            int row = dr[k] + i;
            int col = dc[k] + j;
            if(row >= 0 && row < n && col >= 0 && col < m && grid2[row][col] == 1){
                recur(grid1,grid2,row,col,flag);
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size(), m = grid2[0].size();
        int ans = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j] == 1)
               { 
                    int flag = 1;
                    recur(grid1,grid2,i,j,flag);
                    ans += flag;
                }
            }
        }

        return ans;
    }
};