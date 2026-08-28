class Solution {
    bool checktopological( unordered_map<int,vector<int>>&adj, vector<int>&indegree,int n){
        int count=0;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                count++;
                q.push(i);
            }
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();
    
      for(int &v:adj[u]){
        indegree[v]--;
        if(indegree[v]==0){
             count++;
            q.push(v);
        }
      }
        }
        if(count==n){
            return true;
        }
        return false;

    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       int n=numCourses;
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(n,0);

        for(auto &edge : prerequisites){
            int a=edge[0];
            int b=edge[1];
            adj[b].push_back(a);
              indegree[a]++;
        }
      return  checktopological(adj,indegree,n);
    }
};