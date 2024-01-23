class Solution {
public:
int dp[301];
bool helper(int index,string s,
unordered_set<string> &st)
{
    if(index == s.size()){
        return true;
    }
    string temp;
    if(dp[index] != -1) return dp[index];

for(int j=index;j<s.size();j++){
   temp += s[j];
if(st.find(temp) != st.end())
{
if(helper(j+1,s,st)) return dp[index] = 1;
}
}

return dp[index] = 0;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        memset(dp,-1,sizeof(dp));
        for(auto it:wordDict){
            st.insert(it);
        }
return helper(0,s,st);
    }
};
