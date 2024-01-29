class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        unordered_map<int,int> mp;
     int maxLen =0;
 while(j<n)
 {
     mp[nums[j]]++;

    while(mp.size() > 0 && mp[nums[j]]>k)
    {
        mp[nums[i]]--;
        if(mp[nums[i]] == 0)
        {
            mp.erase(nums[i]);
        }
        i++;
    }
 maxLen = max(maxLen,j-i+1);
 j++;
 }
 return maxLen;
    }
};
