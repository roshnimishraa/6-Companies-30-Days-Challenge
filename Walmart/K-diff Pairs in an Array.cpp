Brute Force 
Here we sort the vector to avoid duplicate elements in the set.
Take to loops & if the difference is equal to k, push it to set.
Calculate the set size in the count variable and return it.
Time complexity: O(n^2 logn).
  
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(),nums.end());
        set<vector<int>> res;
        
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(abs(nums[i]-nums[j]) == k)
            {
                res.insert({nums[i],nums[j]});
            }
        }
    }
    count = res.size();
    return count;
    }
};

Efficient Approach 
Here we sort the values and store the element occurrence in the map.
If k=0, then the difference of 2 same elements will be equal to 0.
If not then we’ll iterate the map & will find if the (k-current element) is present in the map.
If present then we’ll increase count.
Also every time we’ll remove the current element from map to avoid repeating elements.
Time complexity: O(nlogn).

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int count=0;
        int left = 0, right = n-1;
    sort(nums.begin(),nums.end());
    unordered_map<int,int> mp;
    if(k<0) return 0;
for(auto it : nums){
    mp[it]++;
}
if(k == 0){
    for(auto it:mp){
        if(it.second>1){
            count++;
        }
    }
}
    else{
        for(auto it:mp){
            it.second--;
            if(mp.count(it.first-k))
            count++;
            it.second++;
        
    }
}
return count;
    }
};
