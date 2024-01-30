class Solution {
public:
    int minNonZeroProduct(int p) {
long long ans=((long long)(1)<<p)-1;
int mod= (1000000000+7);
long long curr = ans -1;
curr = curr % mod;
ans =   ans % mod;
int k =0;
while(k <= p-2)
{
    ans *= curr;
    curr *= curr;
    ans %= mod;
    curr %= mod;
    k++;
}
return ans;
    }
};
