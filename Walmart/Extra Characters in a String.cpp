class Solution 
{
public:
int dp[51];
int helper(string &s,vector<string> &dict,int index)
{
    if(index == s.size()){
        return 0;
    }
    if(dp[index] == -1){
    dp[index] = 1+ helper(s,dict,index+1);
    
for(auto it:dict)
{
    if(s.compare(index,it.size(),it)==0)
    {
        dp[index] = min(dp[index],helper(s,dict,index+it.size()));
    }
}
    }
    return dp[index];
}
int minExtraChar(string s, vector<string>& dictionary)
{
  memset(dp,-1,sizeof(dp));
  return helper(s,dictionary,0);
}
};
