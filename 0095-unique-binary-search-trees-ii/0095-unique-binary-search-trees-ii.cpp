class Solution {
public:

    vector<TreeNode*> solve(int start, int end) {

        // Base case
        if (start > end) {
            return {NULL};
        }

        vector<TreeNode*> ans;

        // Har number ko root bana ke dekho
        for (int i = start; i <= end; i++) {

            // Left subtree ke saare possible BST
            vector<TreeNode*> leftTrees = solve(start, i - 1);

            // Right subtree ke saare possible BST
            vector<TreeNode*> rightTrees = solve(i + 1, end);

            // Har left tree ko har right tree ke saath combine karo
            for (TreeNode* left : leftTrees) {

                for (TreeNode* right : rightTrees) {

                    TreeNode* root = new TreeNode(i);

                    root->left = left;
                    root->right = right;

                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {

        return solve(1, n);
    }
};