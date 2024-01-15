
Time Complexity: O(2^N)
Space Complexity: O(K)

class Solution {
public:
void helper(int index,int sum,int k,int n,vector<int> &output,vector<vector<int>> &ans)
{
if(sum == n){
if(k == 0)
{
// k is required no. of elements 
    ans.push_back(output);
}
    return;
}
if(index == 10) {
    return;
}
// sum is greater than target then return 
if(sum > n) { 
return;
}

// pick 
output.push_back(index);
helper(index+1,sum+index,k-1,n,output,ans);
// backtracking
output.pop_back();
// not pick 
helper(index+1,sum,k,n,output,ans);
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> output;
        int sum = 0,index = 1;
    helper(index,sum,k,n,output,ans);
    return ans;
    }
};
