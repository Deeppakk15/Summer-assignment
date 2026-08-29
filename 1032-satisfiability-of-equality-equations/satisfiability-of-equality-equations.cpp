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
    void Union(int x,int y){
        int x_parent=Find(x);
        int y_parent=Find(y);

        if(x_parent==y_parent){
            return;
        }

        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[y_parent]>rank[x_parent]){
            parent[x_parent]=y_parent;
        }
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]++; 
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26);
        for(auto st:equations){
            char x=st[0];
            char y=st[3];
            char symbol=st[1];
            if(symbol =='='){
            dsu.Union(x-'a',y-'a');
            }
        }

          for(auto st:equations){
            char x=st[0];
            char y=st[3];
            char symbol=st[1];
            if(symbol =='!'){
              int x_parent= dsu.Find(x-'a');
             int  y_parent= dsu.Find(y-'a');

              if(x_parent == y_parent){
                return false;
              }
            }
        }
        return true;
    }
};