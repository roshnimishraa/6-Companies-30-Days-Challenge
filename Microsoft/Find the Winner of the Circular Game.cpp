Find the Winner of the Circular Game or Joseph Problem 

Time complexity: T(N-1)+C = O(N)
Space complexity: O(1), As we are not using any extra space

class Solution {
    private:
    int helper(int n,int k){
        // base case 
    if(n == 1) {
        return 0; //for 1,2,.. return 1(idx 0)
    }
return (helper(n-1,k)+k)%n;
    }
public:
    int findTheWinner(int n, int k) {
int ans = helper(n,k) + 1; //+1 for 1 based indexing 
return ans;
    }
};
