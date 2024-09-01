class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        int i = 0;
        vector<vector<int>> ans(m,vector<int>(n,0));
        if(((n*m) < size) || ((n*m) > size) ){
            return {};
        }
        int row = 0;
        while(i < size)
        {
            int k = n;
            int col = 0;
            while(k--){
                ans[row][col] = original[i];
                i++;
                col++;
            }
            row++;
        }

        return ans;
    }
};