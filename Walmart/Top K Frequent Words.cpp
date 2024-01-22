class Solution {
public:
static bool cmp(pair<string, int>& a, 
         pair<string, int>& b) 
{
 if (a.second == b.second)
    return a.first.compare(b.first) <0;
    
return a.second > b.second;
    
}
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> freq;
        for(string s:words)
        {
            freq[s]++;
        }
     //sort the map based on value
     vector<pair<string,int>> vec;
for(auto &it:freq){
    vec.push_back(it);
}

// sort using comparator function 
sort(vec.begin(),vec.end(),cmp);

vector<string> ans;
// put first k words in final vector
for(int i=0;i<k;i++){
    ans.push_back(vec[i].first);
}
return ans;
    }
};
