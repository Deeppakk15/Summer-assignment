class DSU{
 public:
    vector<int>parent;
    vector<int>rank;
  
   DSU(int n){
   parent.resize(n+1);
   rank.resize(n+1,0);
   for(int i=1;i<=n;i++){
    parent[i]=i;
   }
   } 
int Find(int x){
    if(parent[x]==x){
        return x;
    }
 return parent[x]=Find(parent[x]);
}

void Union(int x ,int y){
int parent_x=Find(x);
int parent_y=Find(y);

if(parent_x==parent_y){
    return;
}

if(rank[parent_x]>rank[parent_y]){
     parent[parent_y]=parent_x;
}
else if(rank[parent_y]>rank[parent_x]){
    parent[parent_x]=parent_y;
}
else{
  parent[parent_y]=parent_x;
  rank[parent_x]++;
}
}
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n);  
        for(auto edge :edges){
            int u=edge[0];
            int v=edge[1];
          
          if(dsu.Find(u)==dsu.Find(v)){
            return edge;
          }
          else{
            dsu.Union(u,v);
          }
        }
        return {};
    }
};