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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        int depth = 0;
      queue<TreeNode*> q;
      vector<int>temp;
      vector<vector<int>>ans;
      int count=0;
      q.push(root);
      while(!q.empty()){
        count=q.size();
        temp.clear();
        for(int i=0;i<count;i++){
          TreeNode* root= q.front();
          q.pop();
          temp.push_back(root->val);
          if(root->left!=NULL){
            q.push(root->left);
          }
           if(root->right!=NULL){
            q.push(root->right);
          }
        }
        if(depth%2!=0){
          reverse(temp.begin(),temp.end());
          ans.push_back(temp);
        }
        else{
            ans.push_back(temp);
        }
        depth++;
      }
      return ans;
    }
};