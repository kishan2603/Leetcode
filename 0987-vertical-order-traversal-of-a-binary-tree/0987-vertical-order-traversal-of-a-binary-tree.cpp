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
    vector<tuple<int,int,int>> v; // {col,row,node}
    unordered_map<TreeNode*,int> c;
    unordered_map<TreeNode*,int> r;
    void dfs(TreeNode* curr){
        if(curr==nullptr) return;
        if(curr->left!=nullptr){
            v.push_back({c[curr]-1,r[curr]+1,curr->left->val});
            c[curr->left] = c[curr]-1;
            r[curr->left] = r[curr]+1;
        }
        if(curr->right!=nullptr){
            v.push_back({c[curr]+1,r[curr]+1,curr->right->val});
            c[curr->right] = c[curr]+1;
            r[curr->right] = r[curr]+1;
        }
        dfs(curr->left);
        dfs(curr->right);
    }
    vector<vector<int>> verticalTraversal(TreeNode* curr) {
        if(curr==nullptr) return {};
        v.push_back({0,0,curr->val});
        r[curr] = 0;
        c[curr] = 0;
        dfs(curr);
        sort(v.begin(),v.end());
        int n = v.size();
        vector<vector<int>> result;
        vector<int> temp;
        temp.push_back(get<2>(v[0]));
        for(int i=1;i<n;i++){
            if(get<0>(v[i])==get<0>(v[i-1])){
                temp.push_back(get<2>(v[i]));
            }
            else{
                result.push_back(temp);
                temp = {get<2>(v[i])};
            }
        }
        result.push_back(temp);
        return result;
    }
};