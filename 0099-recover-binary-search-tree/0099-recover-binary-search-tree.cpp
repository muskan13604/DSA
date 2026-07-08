class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {

        // Base case
        if (root == NULL) {
            return;
        }

        // Left
        inorder(root->left);

        // Node
        if (prev != NULL && prev->val > root->val) {

            // Pehli mistake
            if (first == NULL) {
                first = prev;
            }

            // Har mistake par current node update
            second = root;
        }

        prev = root;

        // Right
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {

        inorder(root);

        swap(first->val, second->val);
    }
};