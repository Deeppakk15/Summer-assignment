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
 */                                                                 ///  inorder traversall -- LNR
class Solution {    
  private:
  void inorderprint(TreeNode* root,vector<int>&ans) {
        if(root==NULL) { 
                 return  ;
        }
           inorderprint(root->left,ans);
            ans.push_back(root->val);
         inorderprint(root->right,ans);
        //   ans.push_back(root->val);
  }          
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;                                          //revise  later
        inorderprint(root,ans);
        return ans;
    }
};