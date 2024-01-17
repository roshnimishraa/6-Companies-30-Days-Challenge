class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
      int n = nums.size();
      set<vector<int>> st;
      int i,j;
      for(int i=0;i<n;i++){
          vector<int> temp;
          int count=0;
          for(int j=i;j<n;j++){
             temp.push_back(nums[j]);
             if(nums[j] % p == 0){
                 count++;
             }
             if(count > k){
                 break;
             }
             st.insert(temp);
          }
      }
      return st.size();  
    }
};
