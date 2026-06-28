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
    bool checktree(TreeNode* root,long minimumval , long maximumval){
  if(root==NULL) return true;
  if(root->val<=minimumval|| root->val>=maximumval){
    return false;
  }
   bool left =checktree(root->left,minimumval,root->val);
   bool right= checktree(root->right,root->val, maximumval);
   return left && right;
    }
public:
    bool isValidBST(TreeNode* root) {
return checktree(root,LONG_MIN,LONG_MAX);
    }
};
