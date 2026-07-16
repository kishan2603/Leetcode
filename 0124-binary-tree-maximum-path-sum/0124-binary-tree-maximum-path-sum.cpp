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
    int mx;
    int f(TreeNode* root){
        if(root==nullptr) return 0;
        int left = max(0,f(root->left));
        int right = max(0,f(root->right));
        int sum = root->val + left + right;
        mx = max(mx,sum);
        return root->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        mx = -1e9;
        int x = f(root);
        return mx;
    }
};