class Solution {
public:
    # define tt tuple<int,int,int>
    vector<list<pair<int,int>>> graph;
    void make_graph(vector<vector<int>>& flights,int n){
        graph.resize(n,list<pair<int,int>>());
        for(auto e : flights){
            graph[e[0]].push_back({e[1],e[2]});
        }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {   
        make_graph(flights,n);
        priority_queue<tt,vector<tt>,greater<tt>> pq;
        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX)); // {node, edged}
        dist[src][0] = 0;
        pq.push({0,src,0}); // {cost,node,edges}
        while(!pq.empty()){
            auto [cost, node, edges] = pq.top();
            pq.pop();
            if(node==dst) return cost;
            if(edges==k+1) continue;
            for(auto [curr, w] : graph[node]){
                int newcost = cost + w;
                if(newcost<dist[curr][edges+1]){
                    dist[curr][edges+1] = newcost;
                    pq.push({newcost,curr,edges+1});
                }
            }
        }
    return -1;
    }
};