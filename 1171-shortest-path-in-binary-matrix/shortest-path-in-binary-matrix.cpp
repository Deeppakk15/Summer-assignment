class Solution {
    vector<vector<int>>direction{
    {1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,1},{1,-1},{-1,1}
    };
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
     if(grid[0][0]==1 || grid[m-1][n-1]==1){
            return -1;
     }
    queue<pair<int,pair<int,int>>>q;
        
    q.push({1,{0,0}});
    grid[0][0]=1;

    while(!q.empty()){
        pair<int,pair<int,int>>temp=q.front();
        q.pop();
        pair<int,int>temp2=temp.second;
        int step=temp.first;
        int i=temp2.first;
        int j=temp2.second;

if(i==n-1 && j==m-1){
    return step;
}
        for(auto dir :direction){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
     
       if(new_i>=0 && new_j>=0 && new_i<m && new_j<n && grid[new_i][new_j]!=1){
            q.push({step+1,{new_i,new_j}});
            grid[new_i][new_j]=1;
       }
        }

    }

return -1;
    }
};