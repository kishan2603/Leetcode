class Solution {
public:
    # define pp pair<int,vector<int>>
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for(auto e : points){
            int dist = (e[0]*e[0]) + (e[1]*e[1]);
            pq.push({dist,e});
        }
        vector<vector<int>> result;
        for(int i=1;i<=k;i++){
            pp temp = pq.top();
            pq.pop();
            result.push_back(temp.second);
        }
        return result;
    }
};