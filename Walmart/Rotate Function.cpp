class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
      int ans= INT_MIN;
      int n = nums.size();
      int sum=0,sum2=0;
      for(int i=0;i<n;i++){
          sum += nums[i];
          sum2 += nums[i]*i;
      }
      for(int i=n-1;i>=0;i--){
sum2 = sum2-(nums[i]*(n-1))+(sum-nums[i]);
ans = max(ans,sum2);
      }
      return ans;
    }
};
