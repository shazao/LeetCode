/* Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
] */

// Star: 7.5.
// Info.: One-time pass.

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int> > rtn;
        if (root == NULL)
            return rtn;
            
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        std::vector<int> lv;
        while (q.empty() == false) {
            TreeNode * tn = q.front();
            q.pop();
            lv.push_back(tn->val);
            
            if (q.front() == NULL) {
                rtn.push_back(lv);
                lv.clear();
            }
            
            if (tn->left)
                q.push(tn->left);
            if (tn->right)
                q.push(tn->right);
            
            if (q.front() == NULL)
                if (q.size() <= 1)
                    break;
                else {
                    q.pop();
                    q.push(NULL);
                }
        }
        
        return rtn;
    }
};
