class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        string ans="";
    for(auto it:s){
        mp[it]++;
    }
priority_queue<pair<int,char>> pq;
for(auto it:mp){
    char val = it.first;
    int freq = it.second;
    pq.push({freq,val});
}

while(!pq.empty()){
    int n = pq.top().first;
    while(n--){
        ans+= pq.top().second;
    }
    pq.pop();
}
return ans;
    }
};
