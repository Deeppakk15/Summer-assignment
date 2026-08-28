class Solution {
    bool bfs(vector<vector<int>>& graph,int n,int i,int currntcolor,vector<int>&colors){
    queue<int>q;
    q.push(i);
    colors[i]=currntcolor;
while(!q.empty()){
    int u=q.front();
    q.pop();
    for(int &v:graph[u]){
        if(colors[v]==colors[u]){
            return false;
        }
       else if(colors[v]==-1){
        colors[v]=1-colors[u];
        q.push(v);
       }
    }
}
return true;

    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n =graph.size();
        vector<int>colors(n,-1);
        for(int i=0;i<n;i++){
            if(colors[i]==-1){
                if(bfs(graph,n,i,1,colors)==false) return false;
            }
        }
        return true;
    }
};