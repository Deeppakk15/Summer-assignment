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
    void  mindiffinbst(TreeNode* root, int &mindiff,TreeNode* &prev){
        if(root==NULL){
            return;
        }
     
        mindiffinbst(root->left,mindiff,prev);
        if(prev!=NULL){
        mindiff=min(mindiff,abs(prev->val-root->val));
        }
        prev=root;
        mindiffinbst(root->right,mindiff,prev);
    }
public:
    int minDiffInBST(TreeNode* root) {
        int mindiff=INT_MAX;
        TreeNode*prev=NULL;
        mindiffinbst(root,mindiff,prev);
        return mindiff;
    }
};