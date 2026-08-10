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
    void dfs(TreeNode* root,vector<int>& v){
        if(root==nullptr) return;
        dfs(root->left,v);
        v.push_back(root->val);
        dfs(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        dfs(root,v);
        int n = v.size();
        for(int i=0;i<n;i++){
            int target = k - v[i];
            int lo = i+1;
            int hi = n-1;
            while(lo<=hi){
                int mid = lo + (hi-lo)/2;
                if(v[mid]==target) return true;
                else if(v[mid]<target) lo = mid+1;
                else hi = mid-1;
            }
        }
        return false;
    }
};