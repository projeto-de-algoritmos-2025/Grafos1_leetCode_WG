/**
// Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static int max(int a, int b){
    return a>b ? a:b;
}
static int dfs(struct TreeNode* node, int *ans){
    if(!node) return 0;
    int leftGain = dfs(node->left, ans);
    int rightGain = dfs(node->right, ans);
    if(leftGain<0)
        leftGain=0;
    if(rightGain<0)
        rightGain=0;
    int betterNode = node->val + leftGain + rightGain;
    if (betterNode > *ans) 
        *ans = betterNode;
    return node->val + max(leftGain, rightGain);
}

int maxPathSum(struct TreeNode* root) {
    int ans = INT_MIN;
    dfs(root, &ans);
    return ans;
}

