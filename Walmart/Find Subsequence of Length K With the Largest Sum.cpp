class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> original = nums;
    sort(nums.begin(),nums.end());
// a[] = [1,2,3,4] k = 2 temp[]=[3-2,3]
    vector<int> temp(nums.end()-k,nums.end());
  
    // to get original order
unordered_map<int,int> mp;
for(auto x : temp){
    mp[x] += 1;
}
vector<int> ans;
for(auto x : original){
    if(mp[x]-- >0)
    {
        ans.push_back(x);
    }
}
return ans;
    }
};
