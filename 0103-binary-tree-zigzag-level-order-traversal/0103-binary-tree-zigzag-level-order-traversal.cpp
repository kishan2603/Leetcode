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
        if(root==nullptr) return {};
        vector<vector<int>> zigzag;
        queue<TreeNode*> q;
        q.push(root);
        bool isLeft = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            while(size--){
                TreeNode* curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if(curr->left!=nullptr) q.push(curr->left);
                if(curr->right!=nullptr) q.push(curr->right);
            }
            if(!isLeft) reverse(level.begin(),level.end());
            zigzag.push_back(level);
            isLeft = !isLeft;
        }
        return zigzag;
    }
};