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
int counttree(TreeNode* root, int& ans){
    if(root==NULL){
    return 0;
    }
     
   int left =counttree(root->left,ans);
   int right= counttree(root->right,ans);
    ans=max(ans,left+right);
     return max(left,right)+1;
  
   
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
         counttree(root,ans);
         return ans;
    }
};