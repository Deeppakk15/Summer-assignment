class Solution {
    void helper(int u,int n,vector<bool>&visited,vector<vector<int>>& isConnected){
        visited[u]=true;

        for(int v=0;v<n;v++)
      if(!visited[v] && isConnected[u][v]==1){
         helper(v,n,visited,isConnected);
      }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
         vector<bool>visited(n,false);
         int count=0;
         for(int i=0;i<n;i++){
            if(!visited[i]){
                helper(i,n,visited,isConnected);
                count++;
            }
         }
       return count;
    }
};