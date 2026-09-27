class Solution {
public:

    int solve(TreeNode* root, int maxSoFar) {
        if(root == NULL) {
            return 0;
        }

        int count = 0;

        if(root->val >= maxSoFar) {
            count = 1;
        }

        maxSoFar = max(maxSoFar, root->val);

        int left = solve(root->left, maxSoFar);
        int right = solve(root->right, maxSoFar);

        return count + left + right;
    }

    int goodNodes(TreeNode* root) {
        return solve(root, root->val);
    }
};