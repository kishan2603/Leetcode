class Solution {
public:
    int m,n;
    bool dfs(int r,int c, vector<vector<bool>>& visited, vector<vector<int>>& grid){
        if(r<0 || c<0 || r>=m || c>=n || visited[r][c] || grid[r][c]==1) return true;
        visited[r][c] = true;
        bool result = true;
        if(r==0 || c==0 || r==m-1 || c==n-1) result = false;
        bool r1 = dfs(r+1,c,visited,grid);
        bool r2 = dfs(r,c+1,visited,grid);
        bool r3 = dfs(r-1,c,visited,grid);
        bool r4 = dfs(r,c-1,visited,grid);
        result = result && r1 && r2 && r3 && r4;
        return result;
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]==0){
                    bool result = dfs(i,j,visited,grid);
                    if(result) count++;
                }
            }
        }
        return count;
    }
};