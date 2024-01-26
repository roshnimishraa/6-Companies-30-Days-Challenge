class KthLargest {
public:
     // min-heap
priority_queue<int,vector<int>,greater<int>> pq;
int K;
    KthLargest(int k, vector<int>& nums) {
   K=k;
for(int i=0;i<nums.size();i++)
{
    pq.push(nums[i]);
    if(pq.size()>k){
        pq.pop();
    }
}
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > K){
            pq.pop();
        }
        // always valid call
        return pq.top();
    }
};
