class Solution {
void topological( unordered_map<int,vector<int>>&adj,int n,vector<int>&indegree,vector<int>&ans){
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

while(!q.empty()){
    int u=q.front();
    q.pop();
    ans.push_back(u);

    for(int &v :adj[u]){
        indegree[v]--;
        if(indegree[v]==0)
        q.push(v);
    }
}

}
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
      unordered_map<int,vector<int>>adj ;
      vector<int>indegree(n,0);
    for(int u=0;u<n;u++){
        for(int &v:graph[u]){
            adj[v].push_back(u);
         indegree[u]++;
        }
    }

vector<int>ans;

topological(adj,n,indegree,ans);
sort(ans.begin(),ans.end());
return ans;
    }
};