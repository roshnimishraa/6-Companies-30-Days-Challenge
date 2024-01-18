Approach 1: Find Mid
Time Complexity : O(n logn) for sort + O(n) for loop = O(n logn)
Space complexity : O(1)

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int median = n/2;
        int moves = 0;
    for(int i=0;i<n;i++){
        moves += abs(nums[i] - nums[median]);
    }
    return moves;
    }
};


Approach 1: 
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start = 0;
        int end = nums.size()-1;
        int count=0;
        while(start<end){
            count+= nums[end]-nums[start];
            start++;
            end--;
        }
        return count;
    }
};
