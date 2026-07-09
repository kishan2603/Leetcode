class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n,1);
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff) comp[i] = comp[i-1];
            else comp[i] = comp[i-1]+1;
        }
        vector<bool> result;
        for(auto pair : queries){
            int u = pair[0];
            int v = pair[1];
            if(comp[u]==comp[v]) result.push_back(true); 
            else result.push_back(false); 
        }
        return result;
    }
};