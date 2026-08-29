class Solution {
    void dfs(unordered_map<int, vector<int>> &adj,int u,int n,vector<bool>&visited,int &count){
        visited[u]=true;
        count++;
        for(int &v:adj[u]){
            if(!visited[v]){
                  dfs(adj,v, n, visited,count);
            }
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(n, false);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long remainigsize=n;
        int count=0;
        long long ans=0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(adj,i, n, visited,count);
              ans=ans+count*(remainigsize-count);    
                remainigsize=remainigsize-count;
                count=0;
            }
        }
        return ans;
    }
};