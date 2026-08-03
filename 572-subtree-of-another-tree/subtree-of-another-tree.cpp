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
bool checksubtree(TreeNode* root,TreeNode* subRoot){
 if(root==NULL && subRoot==NULL) return true;
 if(root==NULL || subRoot==NULL ) return false;
 if(root->val !=subRoot->val) return false;
 return  checksubtree(root->left,subRoot->left) && checksubtree(root->right,subRoot->right);
}

bool issubtree(TreeNode* root, TreeNode* subRoot){
// if(root==NULL && subRoot ==NULL   ) return true;
// if(root!=NULL && subRoot ==NULL)    return true;
// if(root==NULL && subRoot !=NULL)  return false;
if(root==NULL) return false;
if(root->val == subRoot->val){
   if (checksubtree(root,subRoot)) return true;
}
 return issubtree(root->left,subRoot) || issubtree(root->right,subRoot);


    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
     return    issubtree(root,subRoot);
    }
};