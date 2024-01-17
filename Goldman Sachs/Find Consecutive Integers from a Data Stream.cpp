class DataStream {
public:
int value,k,count;
    DataStream(int val, int K) {
        value = val;
        k = K;
        count =0;
    }
    
    bool consec(int num) {
        if(num != value){
            count =0;
            return false;
        }
    count++;
    if(count >= k){
        return true;
        
    }
    return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
