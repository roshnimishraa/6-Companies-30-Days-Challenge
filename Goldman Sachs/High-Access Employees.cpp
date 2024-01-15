TC : O(N LOG N)
SC : O(N) 
  

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string,vector<int>> mp;
 
    for(auto it: access_times){
        string name = it[0];
        int time = stoi(it[1]);
    mp[name].push_back(time);
    }

// sort each employee according to access times 
for(auto &it :mp){
    sort(it.second.begin(),it.second.end());
}

vector<string> ans;
for(auto &it : mp){
    vector<int> &time = it.second;
//i and i + 2 in the range of 1 hour then i + 1 also in the range of 1 hour.
for(int i=2;i<time.size();i++){
    // (0549 - 0532 < 1hr)
    if(time[i] - time[i-2] < 100){
        ans.push_back(it.first);
        break;
    }
}
}
return ans;
    }
};
