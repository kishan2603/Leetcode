class Solution {
public:
    vector<list<pair<int,int>>> graph;
    void make_graph(vector<vector<int>>& times, int n){
        graph.resize(n+1,list<pair<int,int>>());
        for(auto e : times){
            graph[e[0]].push_back({e[1],e[2]});
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        make_graph(times,n);
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k}); // {d, node}
        while(!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if(d>dist[node]) continue;
            for(auto [curr, w] : graph[node]){
                if(dist[curr]>dist[node]+w){
                    dist[curr] = dist[node] + w;
                    pq.push({dist[curr],curr});
                }
            }
        }
        int ans = -1;
        for(int i=1;i<n+1;i++){
            int d = dist[i];
            if(d==INT_MAX) return -1;
            ans = max(ans,d);
        }
        return ans;
    }
};