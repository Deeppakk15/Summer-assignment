class Solution {
    void dfs(vector<vector<char>>& grid,int m,int n, int i,int j){
        if(i>=m||j>=n||i<0||j<0||grid[i][j]=='0'||grid[i][j]=='#'){
        return;
        }
        grid[i][j]='#';

dfs(grid,m,n,i,j+1);
dfs(grid,m,n,i,j-1);
dfs(grid,m,n,i-1,j);
dfs(grid,m,n,i+1,j);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                dfs(grid,m,n,i,j);
                count++;
                }
            }
        }
        return count;
    }
};