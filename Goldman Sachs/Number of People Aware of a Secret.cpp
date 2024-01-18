
class Solution {
public:
int mod = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> t(n+1,0);
long long numOfPeopleSharingSecret =0;
t[1] = 1;
for(int i=2;i<=n;i++){
    long long numOfNewPeopleSharingSecret = t[max(0,i-delay)];
long long numOfPeopleForgettingSecret = t[max(0,i-forget)];

numOfPeopleSharingSecret = (numOfPeopleSharingSecret + numOfNewPeopleSharingSecret - numOfPeopleForgettingSecret + mod)%mod;
t[i] = numOfPeopleSharingSecret%mod;
}
long long ans = 0;
for(int i=n-forget+1; i<=n; i++){
    ans = (ans + t[i])%mod;
}
return ans%mod;
    }
};
