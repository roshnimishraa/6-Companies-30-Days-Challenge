class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
       int mod = 1000000007;
   priority_queue<int,vector<int>,greater<int>> pq;     
   int n = nums.size();
   for(int i=0;i<n;i++){
       pq.push(nums[i]);
   }

   while(k>0)
   {
    int smallest = pq.top();
    pq.pop();
      smallest++;
    pq.push(smallest);
  k--;
   }
   long ans = 1;
   while(!pq.empty())
   {
       ans = ((ans * pq.top()) % mod);
       pq.pop();
   }
   return (int)ans;
    }
};
