class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        unordered_map<long long,long long> mp;
        long long edges = 0;
        for(auto v : wall){
            long long idx = 0;
            for(int i=0;i<v.size()-1;i++){
                idx += 1LL*v[i];
                mp[idx] ++;
                edges = max(edges,mp[idx]);
            }
        }
        return (int)(n-edges);
    }
};