class Solution {
     vector<vector<int>>direction{
            {-1,0},{1,0},{0,-1},{0,1},
         // UP     Down   left   right
        };
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshcount=0;
        int m=grid.size();
        int n=grid[0].size();
    queue<pair<int,int>>q;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
    if(grid[i][j]==2){
    q.push({i,j});
    }
    if(grid[i][j]==1){
        freshcount++;
    }
        }
    }   

if(freshcount==0){
    return 0;
}
int minute=0;
    while(!q.empty()){
        int size=q.size();

        while(size--){
          pair<int,int>temp=q.front();
          q.pop();
          int i=temp.first;
          int j=temp.second;
 
      for(auto it:direction){
        int new_i=i+it[0];
        int new_j=j+it[1];

       if(new_i<m && new_i>=0 && new_j<n && new_j>=0 && grid[new_i][new_j]==1) {
            grid[new_i][new_j]=2;
            q.push({new_i,new_j});
            freshcount--;
       }
      }       
        }
        minute++;
    }
if(freshcount==0){
 return minute-1;
}
return -1 ;

    }
};