class Solution {
    private:
    int i,j,row,col;
public:
    Solution(int m, int n) {
        i=0,j=0;
        row = m, col=n;
    }
    
    vector<int> flip() {
     if(j>= col){
         i++;
         j=0;
     }   
     if(i>=row){
         i=0;
     }
     vector<int> ans={i,j};
     j++;
     return ans;
    }
    
    void reset() {
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
