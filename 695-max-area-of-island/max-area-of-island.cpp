class Solution {
  void dfs(vector<vector<int>>& grid,int m,int n,int i,int j,int &count){
        if(i>=m||j>=n|| i<0||j<0||grid[i][j]==0||grid[i][j]==-1){
            return;
        }
    grid[i][j]=-1;
    count++;
    dfs(grid,m,n,i,j+1,count);
    dfs(grid,m,n,i,j-1,count);
    dfs(grid,m,n,i+1,j,count);
    dfs(grid,m,n,i-1,j,count);

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int m=grid.size();
      int n=grid[0].size();
      int count=0;
      int maxcount=INT_MIN;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                dfs(grid,m,n,i,j,count);
                maxcount=max(maxcount,count);
                count=0;
            }
        }
      }  
      if(maxcount==INT_MIN){
        return 0;
      }
      return maxcount;
    }
};