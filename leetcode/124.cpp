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
    const int inf = 1e9;
    pair<int,int> _go(TreeNode* root) {
        if(root == NULL) return {-inf,-inf};
        auto l = _go(root->left);
        auto r = _go(root->right);
        pair<int,int> res;
        int z= root->val;
        if (l.second > 0) z+=l.second;
        if (r.second > 0) z+=r.second;
        res.first = max( max(l.first, r.first), z);
        int y = max(l.second, r.second);
        res.second = (y > 0 ? y : 0) + root->val;
        return res;
    }
    
    
    int maxPathSum(TreeNode* root) {
        auto ans = _go(root);
        return ans.first;
    }
};
// idea is that we have the following cases
// select the max path value from one of child node
// considering the current node, select the best height value at left and right child
// add the values only if they are +ve else leave them
