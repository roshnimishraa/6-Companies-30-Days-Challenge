class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int arr[n];
for(int i=0;i<n;i++){
    arr[i] = abs(s[i]-t[i]);
}

int cost=0;
int start=0;
int maxLen = INT_MIN;
for(int i=0;i<n;i++){
    cost += arr[i];
while(cost > maxCost){
    cost -= arr[start++];
    
}
maxLen = max(maxLen,i-start+1);
}
return maxLen;
    }
};
