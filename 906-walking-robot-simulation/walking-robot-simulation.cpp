class Solution {
public:

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        int row = 0, col = 0;
        int n = commands.size();
        unordered_set<string> st;
        for(auto &it : obstacles)
        {
            st.insert(to_string(it[0])+"#"+to_string(it[1]));
        }
        vector<vector<int>> dr={
            {0,1},{1,0},{0,-1},{-1,0}
        };
        int dir = 0,ans = 0;
        for(int i=0;i<n;i++){
            if(commands[i] == -1){
                dir++;
            }
            else if(commands[i] == -2)
            {
                dir--;
            }
            else{
                for(int j=0;j<commands[i];j++){
                    string s = to_string(row + dr[dir][0])+"#"+to_string(col + dr[dir][1]);
                    if(st.find(s) != st.end())
                    {
                        break;
                    }
                    row += dr[dir][0];
                    col += dr[dir][1];
                }
                ans = max(ans,row*row + col * col);
            }

            if(dir == -1){
                dir = 3;
            }
            if(dir == 4){
                dir = 0;
            }
        }

        return ans;

    }
};