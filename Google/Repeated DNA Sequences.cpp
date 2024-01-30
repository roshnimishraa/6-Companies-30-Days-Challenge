class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        string curr="";
        vector<string> ans;
        unordered_map<string,int> mp;
    for(int i=0;i+10<=s.length();i++){
        curr = s.substr(i,10);
        // if string not exist in map
    if(mp.find(curr) == mp.end()){
         mp.insert({curr,0});
    }
   else if(!mp[curr]){
        ans.push_back(curr);
        mp[curr]++;
    }
    }
    return ans;
    }
};
