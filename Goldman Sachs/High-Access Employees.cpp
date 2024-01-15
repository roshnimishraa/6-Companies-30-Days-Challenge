TC : O(N LOG N)
SC : O(N) 
  

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
    unordered_map<string,vector<int>> mp;
for(auto it: access_times){
    int time = stoi(it[1]); //convert to int 
// employee name and access time
mp[it[0]].push_back(time);
}
//  sort each employee according to access times 
for(auto &it : mp){
    sort(it.second.begin(), it.second.end());
}

//scan sorted access times to check if accessed >= 3 times
vector<string> ans;
for(auto &it : mp)
{
    vector<int> &time = it.second;
for(int i=2;i<time.size();i++){
if(time[i] - time[i-2] < 100){
// store employee in ans and move to another employee
ans.push_back(it.first);
break;

}
}
}
return ans;
    }
};
