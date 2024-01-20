class Solution {
public:
int result=0;
bool isPal(string &s){
    int i=0;
    int j=s.length()-1;
    while(i<j){
        if(s[i] != s[j])
            return false;
   i++;
        j--;
    }
    return true;
}
void dfs(string s,int i,string &s1,string &s2)
{
     int n =s1.length();
        int m = s2.length();
        if(i>=s.length()){
            if(isPal(s1) && isPal(s2)){
  result = max(result,n*m);
            }
  return;
        }
//  pick s[i] for s1 but don't pick s[i] for s2
        s1.push_back(s[i]);
        dfs(s,i+1,s1,s2);
        s1.pop_back();
// pick s[i] for s2 but don't pick s[i] for s1 
        s2.push_back(s[i]);
        dfs(s,i+1,s1,s2);
        s2.pop_back();

// don't pick s[i] at all
dfs(s,i+1,s1,s2);

}
   int maxProduct(string s) {
       string s1="", s2="";
       dfs(s,0,s1,s2);
       return result;
    }
};
