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
    class info{
        public:
       int maxi;
       int mini;
       bool isBST;
       int size;
    };


info helper(TreeNode* root, int &ans)
{
    if(root == NULL){
        return {INT_MIN,INT_MAX,true,0};
    }
info left = helper(root->left,ans);
info right = helper(root->right,ans);

info currNode;
currNode.size = left.size + right.size + root->val;
currNode.maxi = max(root->val, right.maxi);
currNode.mini = min(root->val,left.mini);

// check balanced BST or not 
if(left.isBST && right.isBST && (root->val > left.maxi && root->val < right.mini))
{
    currNode.isBST = true;
}
else{
    currNode.isBST = false;
}

// check current node is balanced tree or not if yes update answer 
if(currNode.isBST){
    ans = max(ans,currNode.size);
}
 return currNode;
}
public:
    int maxSumBST(TreeNode* root) {
        int maxSize = 0;
    info temp = helper(root,maxSize);
    return maxSize;
    }
};
