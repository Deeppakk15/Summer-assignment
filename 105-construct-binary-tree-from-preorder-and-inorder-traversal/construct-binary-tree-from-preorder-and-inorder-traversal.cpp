/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
TreeNode* buildtree(vector<int>& preorder, vector<int>& inorder ,unordered_map<int,int>&mp,int &i,int l,int r) {

if(l>r){
    return NULL;
}

      int value=preorder[i++];
      TreeNode*temp=new TreeNode(value);
    int inorderelemindex=mp[value];

  temp->left=buildtree(preorder,inorder ,mp,i,l, inorderelemindex-1);
  temp->right=buildtree(preorder,inorder ,mp,i , inorderelemindex+1,r);

return temp;
}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     unordered_map<int,int>mp;

     for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
     }
     int l=0;
     int i=0;
     int r=inorder.size()-1;
  return buildtree(preorder,inorder,mp,i,l,r);
    }       
};