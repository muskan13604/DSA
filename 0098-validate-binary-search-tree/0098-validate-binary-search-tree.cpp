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
    void validBST(TreeNode* root, TreeNode* &prev, bool &ans){
        if(root == NULL){
            return;
        }
        validBST(root->left,prev,ans);
        if(prev!= NULL && prev->val>= root->val){
            ans=false;
            return;
        }
        prev = root;
         validBST(root->right,prev,ans);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        bool ans = true;
        validBST(root,prev,ans);
        return ans;
    }
};