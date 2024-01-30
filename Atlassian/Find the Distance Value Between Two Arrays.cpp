class Solution {
    private:
bool isValid(vector<int> &arr2,int target,int d)
{
    int n = arr2.size();
int low=0, high=n-1;
while(low <= high)
{
    int mid = low+(high-low)/2;
if(abs(arr2[mid] - target) <= d){
    return false;
}
else if(arr2[mid] > target){
    high =mid-1;
}
else{
    low = mid+1;
}
}
return true;
}
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count=0;
    sort(arr2.begin(),arr2.end());
  for(auto it: arr1)
  {
      if(isValid(arr2,it,d))
      {
          count++;
      }
  }
  return count;
    }
};
