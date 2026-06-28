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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
       if(root== NULL){
        return {} ;
       }
        queue<TreeNode*>q;
        q.push(root);
        vector<int>temp ;
        while(!q.empty()){
         int count= q.size();
         temp.clear();
         for(int i=0;i<count;i++){
           TreeNode*curntnode=q.front();
           temp.push_back(curntnode->val);
           q.pop();
           if(curntnode->left!=NULL){
            q.push(curntnode->left);
           }
            if(curntnode->right!=NULL){
            q.push(curntnode->right);
           }
        }
         ans.push_back(temp);
        }
        return ans;
    }
};