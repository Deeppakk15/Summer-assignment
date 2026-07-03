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
private:
  TreeNode* buildTreeprepost(vector<int>& preorder, vector<int>& inorder,int &preindex,int preend,int inorderend,unordered_map<int,int>&mp,int inorderstart){
if(preindex>preend){
    return NULL;
}
if(inorderstart>inorderend){
    return NULL;
}
   int element=preorder[preindex];
   TreeNode* root= new TreeNode(element);
   int position=mp[element];
   preindex++;
root->left=buildTreeprepost(preorder,inorder,preindex,preend,position-1,mp,inorderstart);
root->right=buildTreeprepost(preorder, inorder, preindex,preend,inorderend,mp,position+1);
return root;
  }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
       int preindex=0;
     for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
     }
   return buildTreeprepost(preorder,inorder,preindex,preorder.size()-1,inorder.size()-1,mp,0);
    }
};



// class Solution {
// private:
//   TreeNode* buildTreeprepost(vector<int>& preorder, vector<int>& inorder,int preindex,int presize,int insize,unordered_map<int,int>mp,int inorderstart){
// if(preindex>=presize){
//     return NULL;
// }
// if(inorderstart>=insize){
//     return NULL;
// }
//    int element=preorder[preindex];
//    TreeNode* root= new TreeNode(element);
//    int position=mp[element];
// root->left=buildTreeprepost(preorder,inorder,preindex+1,presize,position-1,mp,inorderstart);
// root->right=buildTreeprepost(preorder, inorder, preindex+1,presize,insize,mp,position+1);
// return root;
//   }
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         unordered_map<int,int>mp;
       
//      for(int i=0;i<inorder.size();i++){
//         mp[inorder[i]]=i;
//      }
//    return buildTreeprepost(preorder,inorder,0,preorder.size(),inorder.size(),mp,0);
//     }
// };