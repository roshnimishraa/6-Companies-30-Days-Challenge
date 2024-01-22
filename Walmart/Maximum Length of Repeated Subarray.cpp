class Solution {
public:
int helper(vector<int> &nums1,vector<int> &nums2,int m,int n,vector<vector<int>> &dp){
    if(m==0 || n==0) return dp[m][n] = 0;
    if(dp[m][n] != -1) return dp[m][n];
    if(nums1[m-1] == nums2[n-1]){
return dp[m][n] =1+helper(nums1,nums2,m-1,n-1,dp);
 }
 return dp[m][n] = 0;
}
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m =nums1.size();
        int n = nums2.size();
        int ans=0;
vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
for(int i=1;i<=m;i++)
{
    for(int j=1;j<=n;j++){
        int res = helper(nums1,nums2,i,j,dp);
        ans = max(ans,res);
    }
}
return ans;
    }
};
