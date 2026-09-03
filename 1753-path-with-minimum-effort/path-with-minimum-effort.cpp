class Solution {
    vector<vector<int>>direction{
        {0,1},{1,0},{-1,0},{0,-1}
    };
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

pq.push({0,{0,0}});
vector<vector<int>>path(m,vector<int>(n,INT_MAX));
path[0][0]=0;

while(!pq.empty()){
    auto temp1=pq.top();
    pq.pop();
    int d=temp1.first;
    auto temp2=temp1.second;
    int i=temp2.first;
    int j=temp2.second;
    
for(auto dir:direction){
    int new_i=i+dir[0];
    int new_j=j+dir[1];

    if(new_i>=0 && new_j >=0 && new_i<m && new_j<n){
           int new_effort=max(d,abs(heights[new_i][new_j]-heights[i][j]));
           if(new_effort<path[new_i][new_j]){
            path[new_i][new_j]=new_effort;
           pq.push({new_effort,{new_i,new_j}});
           }
          
    }
}

}
return path[m-1][n-1];
    }
};