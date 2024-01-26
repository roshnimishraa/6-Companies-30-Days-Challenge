class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans=0;
int x=left.size();
int m=right.size();
for(int i=0;i<x;i++)
{
    ans = max(ans,(abs(0-left[i])));
}
for(int i=0;i<m;i++)
{
    ans = max(ans,(abs(n-right[i])));
}
return ans;
    }
};
