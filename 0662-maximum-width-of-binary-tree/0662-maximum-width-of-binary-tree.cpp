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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0LL});
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            long long l,r;
            long long f = q.front().second;
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front().first;
                long long idx = q.front().second;
                q.pop();
                idx-=f;
                if(i==0) l = idx;
                if(i==size-1) r = idx;
                if(temp->left) q.push({temp->left,2*idx});
                if(temp->right) q.push({temp->right,2*idx+1});
            }
            ans = max(ans,(int)(r-l+1));
        }
        return ans;
    }
};