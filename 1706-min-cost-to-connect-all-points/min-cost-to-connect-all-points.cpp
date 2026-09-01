class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,vector<pair<int,int>>>adj;
       int n=points.size();
      for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            vector<int>temp1=points[i];
            vector<int>temp2=points[j];
            int dist= abs(temp1[0]-temp2[0])+abs(temp1[1]-temp2[1]);
              adj[i].push_back({j,dist});
              adj[j].push_back({i,dist});
        }
        }
        vector<bool>visited(n,false);
        pq.push({0,0});
        int sum=0;

        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(visited[node]==true) continue;
            sum=sum+wt;
           visited[node]=true;
          for(auto it :adj[node]){
            int V=it.first;
            int value=it.second;
            if(!visited[V]){
                pq.push({value,V});
            }
          }

        }
    return sum;
    }
};