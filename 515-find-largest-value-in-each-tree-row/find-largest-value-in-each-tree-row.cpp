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
    vector<int> largestValues(TreeNode* root) {
      if (root == NULL)
            return {};
int maxvalue=INT_MIN;
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int k = q.size();

            for (int i = 0; i < k; i++) {
                TreeNode* current = q.front();
                q.pop();

             maxvalue=max(maxvalue,current->val);

                if (current->left)
                    q.push(current->left);

                if (current->right)
                    q.push(current->right);
            }

            ans.push_back(maxvalue);
            maxvalue=INT_MIN;
        }

        return ans;    
    }
};
