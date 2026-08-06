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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        long long sum=0;
        vector<double>ans;
        queue<TreeNode*>q;
         q.push(root);      
        while(!q.empty()){
          int k=q.size();
        for(int i=0;i<k;i++){
          TreeNode* currnt=q.front();
            q.pop();
           sum=sum+currnt->val;
          if(currnt->left){
            q.push(currnt->left);
         }
            if(currnt->right){
            q.push(currnt->right);
          }
            }
     ans.push_back((double)sum/k);
     sum=0;

        }
        return ans;
    }
};