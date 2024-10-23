//question: https://leetcode.com/problems/cousins-in-binary-tree-ii/
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root)
            return nullptr;

        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*, int> parentSum;
        root->val = 0;

        while (!q.empty()) {
            int sz = q.size(), levelSum = 0;
            vector<TreeNode*> levelNodes;

            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelNodes.push_back(node);

                if (node->left) {
                    levelSum += node->left->val;
                    q.push(node->left);
                }

                if (node->right) {
                    levelSum += node->right->val;
                    q.push(node->right);
                }
            }

            for (TreeNode* node : levelNodes) {
                int siblingSum = 0;
                if (node->left)
                    siblingSum += node->left->val;
                if (node->right)
                    siblingSum += node->right->val;

                if (node->left)
                    node->left->val = levelSum - siblingSum;
                if (node->right)
                    node->right->val = levelSum - siblingSum;
            }
        }

        return root;
    }
};