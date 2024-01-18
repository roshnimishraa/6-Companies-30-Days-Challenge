class Solution {
public:
// t[startPos][k]
int t[4001][4001];
int mod = 1e9+7;
long long helper(int start,int end,int k){
    if(k == 0 && start == end){
        return 1;
    }
    if(k == 0 && start != end){
        return 0;
    }
if(t[start+1000][k] != -1){
    return t[start+1000][k];
}

long long forw = helper(start+1,end,k-1);
long long back = helper(start-1,end,k-1);
        return t[1000+start][k] = (forw+back)%mod;
}
    int numberOfWays(int startPos, int endPos, int k) {
        memset(t,-1,sizeof(t));
    long long ans = helper(startPos,endPos,k);
    return ans%mod;
    }
};
