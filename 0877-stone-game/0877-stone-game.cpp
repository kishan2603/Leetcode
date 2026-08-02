class Solution {
public:
    vector<vector<vector<int>>> dp;
    int f(vector<int>& piles, int i, int j, bool turn){
        if(i==j){
            if(turn) return piles[i];
            return 0; 
        }
        if(dp[i][j][turn]!=-1) return dp[i][j][turn];
        if(turn) return dp[i][j][turn] = max(f(piles,i+1,j,!turn)+piles[i], f(piles,i,j-1,!turn)+piles[j]);
        return dp[i][j][turn] = min(f(piles,i+1,j,!turn), f(piles,i,j-1,!turn));
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n,vector<vector<int>>(n,vector<int>(2,-1)));
        int sum = accumulate(piles.begin(),piles.end(),0);
        int sum1 = f(piles,0,n-1,true);
        int sum2 = sum - sum1;
        if(sum1 > sum2) return true;
        return false;
    }
};