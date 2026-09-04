/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
void dfs(Node*&node,Node*&clone,unordered_map<Node*,Node*>&mp){

for(Node*n:node->neighbors){
   if(mp.find(n) ==mp.end()){
    Node*newclone=new Node(n->val);
    clone->neighbors.push_back(newclone);
    mp[n]=newclone;
    dfs(n,newclone,mp);
   }
  else{
    clone->neighbors.push_back(mp[n]);
  }
}


}

public:
    Node* cloneGraph(Node* node) {
    if(!node) return NULL;

    Node * clone_node=new Node(node->val);

    unordered_map<Node*,Node*>mp;
    mp[node]=clone_node;
    dfs(node,clone_node,mp);
    return clone_node;
    }
};