TC : O(log N) 
SC : O(1) 

class Solution {
    private:
    int gcd(int a,int b) {
    if(b== 0){
        return a;
    }
else{
    return gcd(b,a%b);
}
}
public:

    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
    long int l=1, r = INT_MAX;
    long ans = INT_MAX;
long long int lcm = ((long long)divisor1*divisor2)/gcd(divisor1,divisor2);
while(l<=r){
int mid = l+(r-l)/2;
// no. which are not divisible by d1 
int x = mid - mid/divisor1;
// no. which are not divisible by d2 
int y = mid - mid/divisor2;
// no. which are not divisible by both d1 and d2 
int z = mid - mid/lcm;

if(x>=uniqueCnt1 && y >= uniqueCnt2 && z>= uniqueCnt1 + uniqueCnt2)
{
    // minimize
ans = mid;
r = mid-1;
}
else{
   
l = mid+1;
}
}
return ans;
    }
};
