class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
    for(auto &it:nums){
        if(it % 2){
            it = 1;
        }
        else{
            it = 0;
        }
    }
    mp[0] = 1;
    int sum=0, count=0;
    for(auto it:nums){
        sum += it;
        count += mp[sum-k];
        mp[sum]++;
    }
    return count;
    }
};
