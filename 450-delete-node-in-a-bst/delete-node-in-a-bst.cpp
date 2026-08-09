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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
   if(root==NULL){
    return NULL;
   } 
if(root->val==key){
  if(root->left==NULL && root->right==NULL){
    return NULL;
  }

 else if(root->left !=NULL && root->right==NULL){
    TreeNode*temp=root->left;
    delete(root);
    return temp;
 }
  
   else if(root->right !=NULL && root->left==NULL){
    TreeNode*temp=root->right;
    delete(root);
    return temp;
 }

 else if(root->left!=NULL && root->right!=NULL){
 TreeNode*temp= root->right;
while(temp->left!=NULL){
    temp=temp->left;
}

 int minval=temp->val;
 root->val=minval;
 root->right=deleteNode(root->right,minval);
 }

}

    if(key<root->val){
     root->left=   deleteNode(root->left,key);
    }
     if(key>root->val){
     root->right= deleteNode(root->right,key);
    }
     return root;
    }

};