class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
   vector<int> ans;
   int n = nums.size();
   for(auto &it : queries)
   {
    vector<pair<string,int>> v;
for(int i=0;i<n;i++)
{
    int trim = it[1];
int n1 = nums[i].size();
string s = nums[i].substr(n1-trim);
v.push_back({s,i});

}
sort(v.begin(),v.end());
int k = it[0];
ans.push_back(v[k-1].second);
   }     
  return ans;
    }
};
