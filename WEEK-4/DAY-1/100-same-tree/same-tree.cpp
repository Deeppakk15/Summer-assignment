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
class Solution {                                //  need to revise later.
    bool issame(TreeNode* p, TreeNode* q){
    if(p == NULL && q== NULL ){
        return  true;
    }
    if(p==NULL || q==NULL){
        return false;
    }
    if(p->val != q->val){
        return false;
    }


  bool leftsame = issame(p->left,q->left);
  if(leftsame==false){
    return false;
  }
  bool rightsame = issame(p->right,q->right);
  if(rightsame==false){
    return false;
  }
  return true;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
       return issame(p,q);
    }
};











// class Solution {
//     bool issame(TreeNode* p, TreeNode* q){
//        if(p==NULL ||q==NULL){
//         return;
//     }
//     if(p->left->val==q->left->val){
//      issame(p->left,q->left);
//     }
//     else{
//         return false;
//     }
//     if(p->right->val==q->right->val){
//      issame(p->right,q->right);
//     }
//     else{
//         return false;
//     }
       
//     }
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//        return issame(p,q);
//     }
// };  











//     void issame(TreeNode* p, TreeNode* q){
//        if(p==NULL ||q==NULL){
//         return;
//     }
//     if(p->left==q->left){
//      issame(p->left,q->left);
//     }
//     if(p->right==q->right){
//      issame(p->right,q->right);
//     }
       
//     }
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//        return issame(p,q);
//     }
// };  



















// class Solution {
//     bool issame(TreeNode* p, TreeNode* q){
//           if(p==NULL && q==NULL){
//          return true;
//     }
//        if(p==NULL && q!=NULL){
//         return false;
//     }
//     if(q==NULL && p!=NULL){
//         return false;
//     }

//     if(p->val!=q->val){
//      return false;
//     }
//     else{
//        issame(p->left,q->left);
//     }
//     if(p->val!=q->val){
//     return false;
//     }
//     else{
//          issame(p->right,q->right);
//     }
       
//     }
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//        return issame(p,q);
//     }
// };