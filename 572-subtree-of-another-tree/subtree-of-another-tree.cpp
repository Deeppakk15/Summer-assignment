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
    // these condn are also  currect but it is gieven than  root and sub root has at least one node  so these cond are not needed however you can also use this condn but here instead of these three we used condn line 25 for base case when we travrse thrgough all node and dosent fonsd root == subroot
// if(root==NULL && subRoot ==NULL   ) return true;
// if(root!=NULL && subRoot ==NULL)    return true;
// if(root==NULL && subRoot !=NULL)  return false;
if(root==NULL) return false;
if(root->val == subRoot->val){
   if (checksubtree(root,subRoot)) return true;
   //here we ddint check for false beacuse if we return false then remaning tree will not procced and what if we have our ans somewhereelse
}
 return issubtree(root->left,subRoot) || issubtree(root->right,subRoot);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
     return    issubtree(root,subRoot);
    }
};