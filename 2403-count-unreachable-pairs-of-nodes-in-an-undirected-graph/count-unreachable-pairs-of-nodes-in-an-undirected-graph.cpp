class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int Find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = Find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = Find(x);
        int y_parent = Find(y);

        if (x_parent == y_parent) {
            return;
        }
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

};
 class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
   DSU dsu(n);

for(auto edge:edges){
    int u=edge[0];
    int v=edge[1];

    if(dsu.Find(u)!=dsu.Find(v)){
        dsu.Union(u,v);
    }
}
unordered_map<int,int>mp;
for(int i=0;i<n;i++){
  mp[dsu.Find(i)]++;
}
long long remainingsize=n;
int req=n-1;
long long ans=0;
for(auto it :mp){
ans=ans+it.second*(remainingsize-it.second);
remainingsize=remainingsize-it.second;
}

return ans;
    }
};