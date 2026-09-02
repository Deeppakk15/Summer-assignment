class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        queue<pair<int,int>>q;
     for(auto flight:flights){
        int u=flight[0];
        int v=flight[1];
        int wt=flight[2];
     adj[u].push_back({v,wt});
     }
vector<int>path(n,INT_MAX);
int count=0;
q.push({0,src});

while(!q.empty() && count<=k){
    int size=q.size();
    while(size--){
    int node=q.front().second;
    int wt=q.front().first;
    q.pop();
    for(auto it:adj[node]){
        int value=it.first;
        int d=it.second;
        if(d+wt<path[value] && count<=k){
            path[value]=d+wt;
            q.push({d+wt,value});
            
        }
    }
    }
    count++;
}
if(path[dst]==INT_MAX){
    return -1;
}
return path[dst];
    }
};