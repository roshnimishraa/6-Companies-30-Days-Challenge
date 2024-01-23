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
TreeNode* helper(TreeNode *root,int low,int high){
    if(root == NULL) return NULL;

    // left recursion call 
TreeNode* leftNode= helper(root->left,low,high);
if(leftNode != root->left){
    root->left = leftNode;
}
    // right recursion call
TreeNode* rightNode=helper(root->right,low,high);
if(rightNode != root->right){
    root->right = rightNode;
}
if(root->val > high || root->val<low){
if(root->left != nullptr){
    return root->left;
}
else{
    return root->right;
}
}
return root;
}
    TreeNode* trimBST(TreeNode* root, int low, int high) {
      return helper(root,low,high);  
    }
};
