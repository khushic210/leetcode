
class Solution {
public:
    long long findSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return root->val
             + findSum(root->left)
             + findSum(root->right);
    }

    int maxProduct(TreeNode* root) {
        long long totalSum = findSum(root);
        long long maxp = 0;
        const long long MOD = 1000000007;

        queue<TreeNode*> q;
        vector<TreeNode*> nodes;

        q.push(root);


        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            nodes.push_back(node);

            if (node->left) {
                q.push(node->left);
            }
               if (node->right) {
                q.push(node->right);
            }
        }

        unordered_map<TreeNode*, long long> subSum;
 
        for (int i = (int)nodes.size() - 1; i >= 0; i--) {
            TreeNode* node = nodes[i];

            long long sum = node->val;

            if (node->left) {
                sum += subSum[node->left];
            }

            if (node->right) {
                sum += subSum[node->right];
            }

            subSum[node] = sum;

            if (node != root) {
                long long product = sum * (totalSum - sum);
                maxp = max(maxp, product);
            }
        }

        return maxp % MOD;
    }
};

