class Solution {
public:
    void add_edge(int src, int dst, vector<list<int>>& graph, vector<list<int>>& adj){
        graph[src].push_back(dst);
        adj[dst].push_back(src);
    }
    void make_graph(vector<vector<int>>& invocations, vector<list<int>>& graph, vector<list<int>>& adj){
        for(auto e : invocations){
            add_edge(e[0],e[1],graph,adj);
        }
    }
    void dfs(int src,vector<bool>& visited,vector<list<int>>& graph){
        visited[src] = true;
        for(auto nghs : graph[src]){
            if(!visited[nghs]) dfs(nghs,visited,graph);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<list<int>> graph(n,list<int>());
        vector<list<int>> adj(n,list<int>());
        make_graph(invocations,graph,adj);
        vector<bool> visited(n,false);
        dfs(k,visited,graph);

        vector<int> result;
        bool ok = false;
        for(int i=0;i<n;i++){
            if(!visited[i]) result.push_back(i);
            else{
                for(auto nghs : adj[i]){
                    if(!visited[nghs]){
                        ok = true;
                        result.push_back(i);
                        break;
                    }
                }
                if(ok) break;
            }
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++) ans[i] = i;
        if (ok) return ans;
        return result;
    }
};