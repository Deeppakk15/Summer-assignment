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


//both approach is correct either make vector of ans of each leftmost root value or just stor leftmost valuee in ans varible 
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
         if(root==NULL){
            return 0;
        }
        queue<TreeNode*>q;
      
        q.push(root);
         int ans=root->val;
        while(!q.empty()){
         int k= q.size();   
    for(int i=0;i<k;i++)    {
        TreeNode* currnt=q.front();
        q.pop();

if(i==0){
    ans=currnt->val;
}
        if(currnt->left){
            q.push(currnt->left);
        }
            if(currnt->right){
            q.push(currnt->right);
        }

    }
        }
     
        return ans;
    }
};





















// class Solution {
// public:
//     int findBottomLeftValue(TreeNode* root) {
//          if(root==NULL){
//             return 0;
//         }
//         queue<TreeNode*>q;
//         vector<int>ans;
//         q.push(root);
//         while(!q.empty()){
//          int k= q.size();   
//     for(int i=0;i<k;i++)    {
//         TreeNode* currnt=q.front();
//         q.pop();

// if(i==0){
//     ans.push_back(currnt->val);
// }
//         if(currnt->left){
//             q.push(currnt->left);
//         }
//             if(currnt->right){
//             q.push(currnt->right);
//         }

//     }
//         }
//         int k=ans.size()-1;
//        int finalans=ans[k];
//         return finalans;
//     }
// };