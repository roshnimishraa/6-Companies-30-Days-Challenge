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
unordered_map<int,vector<int>> graph;
void buildGraph(TreeNode* root){
    queue<pair<TreeNode*, int>> q;
    q.push({root,-1});
    while(!q.empty()){
    TreeNode *curr = q.front().first;
    int parent = q.front().second;
    q.pop();
    if(parent != -1){
        graph[parent].push_back(curr->val);
        graph[curr->val].push_back(parent);
    }
    if(curr->left){
        q.push({curr->left,curr->val});
    }
    if(curr->right){
        q.push({curr->right,curr->val});
    }
    }
}
    int amountOfTime(TreeNode* root, int start) {
        buildGraph(root);
        int time = -1;
        queue<int> q;
        q.push(start);
        unordered_map<int,bool> visited;
        visited[start] = true;
        while(!q.empty()){
            int n = q.size();
        for(int i=0;i<n;i++){
            int val = q.front();
            q.pop();
            for(auto x:graph[val])
            {
                if(visited[x] == false)
                {
                    visited[x] = true;
                    q.push(x);

                }
            }
        }
        time++;
        }
        return time;
    }
};
