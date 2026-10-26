class Solution {
public:
    vector<vector<bool>> visited;
    int m,n;
    long long dfs(int r, int c,vector<vector<int>>& grid){
        if(r<0 || c<0 || r>=m || c>=n || visited[r][c] || grid[r][c]<=0) return 0;
        visited[r][c] = true;
        return 1LL*grid[r][c] + dfs(r-1,c,grid) + dfs(r,c-1,grid) + dfs(r+1,c,grid) + dfs(r,c+1,grid);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        visited.resize(m,vector<bool>(n,false));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0 && !visited[i][j]){
                    long long result = dfs(i,j,grid);
                    if(result%k==0) ans++;
                }
            }
        }
        return ans;
    }
};