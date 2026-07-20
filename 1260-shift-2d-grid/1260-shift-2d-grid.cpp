class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(k==0) return grid;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m,vector<int>(n));
        vector<vector<int>> temp = grid;
        while(k--){
            for(int j=0;j<n;j++){
                for(int i=0;i<m;i++){
                    result[i][(j+1)%n] = temp[i][j];
                }
            }
            for(int i=0;i<m;i++){
                result[(i+1)%m][0] = temp[i][n-1];
            }
            temp = result;
        }
    return result;
    }
};