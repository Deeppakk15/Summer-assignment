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
   void countgoodnode(TreeNode* root,int &count,int maxelem){
    if(root==NULL){
        return;
    }
    if(root->val>=maxelem){
        count++;
    }
  maxelem=max(maxelem,root->val);
    countgoodnode(root->left,count,maxelem);
    countgoodnode(root->right,count,maxelem);

   }
public:
    int goodNodes(TreeNode* root) {
        int count=0;
        int maxelem=INT_MIN;
        countgoodnode(root,count,maxelem);
        return count;
    }
};