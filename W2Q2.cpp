/*
    Binary Tree Level Order Traversal II

    Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

    For example:
    Given binary tree [3,9,20,null,null,15,7],
            3
           / \
          9  20
            /  \
           15   7
    return its bottom-up level order traversal as:
        [
            [15,7],
            [9,20],
            [3]
        ]
*/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        
        if(root == NULL)
            return {};
        
        vector<vector<int>> res;
        
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        
        q1.push(root);
        
        vector<int> v;
        
        while(!q1.empty() || !q2.empty())
        {
            while(!q1.empty())
            {
                TreeNode* temp = q1.front();
                q1.pop();
                
                v.push_back(temp->val);
                if(temp->left) 
                    q2.push(temp->left);
                if(temp->right)
                    q2.push(temp->right);
            }
            if(v.size() > 0)
                res.push_back(v);
            v.clear();
            
            while(!q2.empty())
            {
                TreeNode* temp = q2.front();
                q2.pop();
                
                v.push_back(temp->val);
                if(temp->left) 
                    q1.push(temp->left);
                if(temp->right)
                    q1.push(temp->right);
            }
            if(v.size() > 0)
                res.push_back(v);
            v.clear();
        }
        
        reverse(res.begin(), res.end());
        
        return res;  
    }
};