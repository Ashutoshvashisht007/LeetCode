class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> ans = matrix;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> mx(m,0);
        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                mx[j] = max(mx[j],matrix[i][j]);
            }
        }
        
        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(matrix[i][j] == -1)
                {
                    ans[i][j] = mx[j];
                }
            }
        }
        
        return ans;
        
    }
};