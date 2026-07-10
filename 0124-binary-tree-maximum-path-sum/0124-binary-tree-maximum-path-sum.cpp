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
    int Sum(TreeNode* root, int &maxSum ){
        if (!root) return 0; 
        int left = Sum(root->left,maxSum);
        int right = Sum(root->right,maxSum);
        left = max(0,left);
        right = max(0, right);
        int leftSum = root->val+left;
        int rightSum = root->val+right;
        int nodeSum = root->val+left+right;
        int node = root->val;
        maxSum = max(maxSum,nodeSum);
        return max(leftSum,rightSum);   
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        Sum(root,maxSum);
        return maxSum;
    }
};