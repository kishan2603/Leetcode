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
    unordered_map<TreeNode*,list<TreeNode*>> graph;
    void dfs(TreeNode* root,TreeNode* parant){
        if(root==nullptr) return;
        if(root->left) graph[root].push_back(root->left);
        if(root->right) graph[root].push_back(root->right);
        if(parant) graph[root].push_back(parant);
        dfs(root->left,root);
        dfs(root->right,root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==nullptr) return{};
        dfs(root,nullptr);
        queue<TreeNode*> q;
        q.push(target);
        int dist = 0;
        unordered_map<TreeNode*,int> m;
        m[target] = 1;
        vector<int> result;
        while(!q.empty() && dist<=k){
            int size = q.size();
            while(size--){
                TreeNode* curr = q.front();
                q.pop();
                m[curr] = 1;
                if(dist==k) result.push_back(curr->val);
                for(auto nghs : graph[curr]){
                    if(m[nghs]==0) q.push(nghs);
                }
            }
            dist++;
        }
    return result;
    }
};