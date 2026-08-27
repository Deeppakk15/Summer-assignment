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
   
    void inorder(TreeNode* root,TreeNode*& curr) {
        if (root==NULL)
            return;
        inorder(root->left,curr);
        curr->right =root;
        curr=root;
        curr->left=NULL;
        inorder(root->right,curr);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {

       TreeNode*dummy=new TreeNode(-1);
       TreeNode*curr =dummy;
        inorder(root,curr);
        return dummy->right;
    }
};