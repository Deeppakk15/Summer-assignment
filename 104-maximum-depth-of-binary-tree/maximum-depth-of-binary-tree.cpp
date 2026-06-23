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
class Solution {                                //inorder == LNR
    private:
    void treecount(TreeNode*root,int &count,int &ans){
        
        if(root==NULL){
            return;
        }
        count++;
        treecount(root->left,count,ans);
         ans=max(ans,count);
        treecount(root->right,count,ans);
        count--;
    }
public:
    int maxDepth(TreeNode* root) {
         int count=0;
         int ans=0;
        treecount(root,count,ans);
        return ans;
    }
};