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
    int height(TreeNode* root){
        if (!root) return 0;
        return 1 + max(height(root->left),height(root->right));
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};
        queue<TreeNode*> q;
        vector<int> result(height(root),0);
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* temp = q.front();
                q.pop();
                result[level] = temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            level++;
        }
        return result;
    }
};