class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;
    unordered_map<string,int> m;
    string curr = "";
    for(int i=0;i+10<=s.size();i++)
    {
        curr = s.substr(i,10);
    if(m.find(curr) == m.end())
    m.insert({curr,0});
    
    else if(!m[curr]){
        res.push_back(curr);
        m[curr]++;
    }
    }  
  return res;
    }
};

