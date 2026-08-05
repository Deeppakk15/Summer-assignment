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
 void  pathsum(TreeNode* root, int targetSum,long long presum, unordered_map<long long,int>&mp,int &count){
if(root==NULL){
    return;
}
presum=presum+root->val;
if(mp.count(presum-targetSum)){
    count=count+mp[presum-targetSum];
}
mp[presum]++;
pathsum(root->left, targetSum,presum,mp,count);
pathsum(root->right,targetSum,presum,mp,count);
// mp.erase(presum);  wrong
mp[presum]--;
if (mp[presum] == 0)
    mp.erase(presum);
      }

      
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        long long presum=0;
        unordered_map<long long,int>mp;
        mp[0]=1;
        int count=0;
        pathsum(root,targetSum,presum,mp,count);
        return count;
    }
};