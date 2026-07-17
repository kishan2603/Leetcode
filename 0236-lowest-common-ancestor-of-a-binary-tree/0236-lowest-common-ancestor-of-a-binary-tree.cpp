/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool find(TreeNode* root, TreeNode* target){
        if(root==nullptr) return false;
        if(root==target) return true;
        return find(root->left,target) || find(root->right,target);
    }
    TreeNode* f(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==p) return p;
        if(root==q) return q;
        bool pInLeft = find(root->left,p);
        bool qInLeft = find(root->left,q);
        if((pInLeft && !qInLeft) || (!pInLeft && qInLeft)) return root;
        if(pInLeft && qInLeft) return f(root->left,p,q);
        return f(root->right,p,q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root,p,q);
    }
};