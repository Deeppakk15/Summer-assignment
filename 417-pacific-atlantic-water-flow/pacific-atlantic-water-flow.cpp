class Solution {
    vector<vector<int>>direction{
        {1,0},{0,1},{-1,0},{0,-1}
    };

    void dfs(vector<vector<int>>& matrix,vector<vector<bool>>&visited,int prev,int m,int n,int i,int j){
        if(i<0 || j<0 || i>=m || j>=n || visited[i][j]==true || matrix[i][j]<prev){
            return;
        }
        visited[i][j]=true;
       prev=matrix[i][j];
        for(auto dir:direction){
           int  new_i=i+dir[0];
           int new_j=j+dir[1];
            dfs(matrix,visited,prev,m,n,new_i,new_j);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<bool>>pacificvisited(m,vector<bool>(n,false));
         vector<vector<bool>>atlanticvisited(m,vector<bool>(n,false));

         for(int j=0;j<n;j++){
            dfs(matrix,pacificvisited,INT_MIN,m,n,0,j);
            dfs(matrix,atlanticvisited,INT_MIN,m,n,m-1,j);
         }
        for(int i=0;i<m;i++){
        dfs(matrix,pacificvisited,INT_MIN,m,n,i,0);
        dfs(matrix,atlanticvisited,INT_MIN,m,n,i,n-1);
         }
     
vector<vector<int>>ans;
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(pacificvisited[i][j]  && atlanticvisited[i][j]){
            ans.push_back({i,j});
        }
    }
}
return ans;
    }
};