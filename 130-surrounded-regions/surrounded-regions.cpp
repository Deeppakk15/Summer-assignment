class Solution {
    vector<vector<int>>direction{
        {1,0},{0,1},{-1,0},{0,-1}
    };
    void dfs(int i,int j,int m,int n,vector<vector<char>>& board){
     if(i<0 || j<0 || i>=m || j>=n || board[i][j]!='O'){
        return;
     }

     board[i][j]='#';
 for(auto dir:direction){
    int new_i=i+dir[0];
    int new_j=j+dir[1];
  dfs(new_i,new_j,m,n,board);

 }
         

    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

for(int j=0;j<n;j++){
dfs(0,j,m,n,board);
dfs(m-1,j,m,n,board);
}

for(int i=0;i<m;i++){
dfs(i,0,m,n,board);
dfs(i,n-1,m,n,board);
}


    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
       if(board[i][j]=='O'){
        board[i][j]='X';
     }
     if(board[i][j]=='#'){
        board[i][j]='O';
     }
        }
    }
    }
};