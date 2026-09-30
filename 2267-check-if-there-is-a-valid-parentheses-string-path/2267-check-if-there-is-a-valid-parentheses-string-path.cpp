class Solution {
public:
    int m;
    int n;
    vector<vector<vector<int>>> dp;
    bool f(vector<vector<char>>& grid, int i, int j, int b){
        if(b<0) return false;
        int r = (m + n - 1) - (i + j + 1);
        if(b > r) return false;
        if(i==m-1 && j==n-1) return b==0;
        if(dp[i][j][b]!=-1) return dp[i][j][b];
        bool ans = false;
        if(i+1 < m){
            int nb = b + (grid[i+1][j]=='(' ? 1 : -1);
            if(f(grid,i+1,j,nb)) ans = true;
        }
        if(!ans && j+1 < n){
            int nb = b + (grid[i][j+1]=='(' ? 1 : -1);
            if(f(grid,i,j+1,nb)) ans = true;
        }
        return dp[i][j][b] = ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if((m + n - 1) % 2 != 0) return false;
        if(grid[0][0]==')') return false;
        dp.resize(m,vector<vector<int>>(n,vector<int>(m+n,-1)));
        return f(grid,0,0,1);
    }
};