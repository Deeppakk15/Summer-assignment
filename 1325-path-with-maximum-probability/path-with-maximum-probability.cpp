class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,vector<double>& succProb, int start_node,
    int end_node) {
        unordered_map<int, vector<pair<int, double>>> adj;
        int i = 0;
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
            i++;
        }
vector<double>path(n,0.0);
priority_queue<pair<double,int>>pq;
path[start_node]=1.0;
pq.push({1.0,start_node});
while(!pq.empty()){
int node=pq.top().second;
double d=pq.top().first;
pq.pop();
for(auto it :adj[node]){
    int currntnode=it.first;
    double value=it.second;

    if(d*value>path[currntnode]){
        path[currntnode]=d*value;
        pq.push({d*value,currntnode});
    }
}
}
return path[end_node];
    }
};