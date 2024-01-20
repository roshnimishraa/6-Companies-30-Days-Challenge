
class Solution {
public:
bool helper(vector<int> &nums,int start,int end)
{
    int n = nums.size();
    int prev=0;
    for(int i=0;i<n;i++){
        if(i<=end && i>=start){
            continue;
        }
        if(nums[i] <= prev){
            //not increasing 2 1  prev=2 
            continue;
        }
        prev = nums[i];
    }
    return true;
}
    int incremovableSubarrayCount(vector<int>& nums) {
        int count=0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(helper(nums,i,j)== true){
                count++;
            }
        }
    }
    return count;
    }
};
