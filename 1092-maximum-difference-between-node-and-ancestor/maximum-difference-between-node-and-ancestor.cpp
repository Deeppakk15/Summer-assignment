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
void maxancestordiff(TreeNode* root ,int minelem,int maxelem,int & maxdif){
if(root==NULL){
    return;
}
minelem=min(minelem,root->val);
maxelem=max(maxelem,root->val);
maxdif=max(maxdif,maxelem-minelem);
maxancestordiff(root->left ,minelem,maxelem,maxdif);
maxancestordiff(root->right ,minelem,maxelem,maxdif);

}
public:
    int maxAncestorDiff(TreeNode* root) {
        int minelem=INT_MAX;
        int maxdif=0;
        int maxelem=0;
        maxancestordiff(root,minelem,maxelem,maxdif);
        return maxdif;
    }
};