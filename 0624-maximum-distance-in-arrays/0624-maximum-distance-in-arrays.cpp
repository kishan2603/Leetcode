class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int mini = arrays[0][0];
        int maxi = arrays[0].back();
        int dist = 0;
        for(int i=1;i<n;i++){
            int lmin = arrays[i][0];
            int lmax = arrays[i].back();

            dist = max({dist, lmax-mini, maxi-lmin});
            mini = min(mini, lmin);
            maxi = max(maxi, lmax);
        }
        return dist;
    }
};