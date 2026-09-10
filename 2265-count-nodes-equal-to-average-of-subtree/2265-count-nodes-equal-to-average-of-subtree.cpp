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
    int count;
    pair<int,int> dfs(TreeNode* root){
        if(root==nullptr) return {0,0};
        auto [leftSum, leftn] = dfs(root->left);
        auto [rightSum, rightn] = dfs(root->right);
        int totalSum = leftSum + rightSum + root->val;
        int totaln = leftn + rightn + 1;
        if(totalSum/totaln == root->val) count++;
        return {totalSum, totaln};
    }
    int averageOfSubtree(TreeNode* root) {
        count = 0;
        auto [x,y] = dfs(root);
        return count;
    }
};