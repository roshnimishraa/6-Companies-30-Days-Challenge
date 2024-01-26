class Solution {
public:
    void isPlace(vector<int>seat, bool &lplace,bool &rplace,bool &mplace){
        for(int i=0;i<seat.size();i++){
            if(seat[i]>=1 && seat[i]<=4)
            lplace=false;
            if(seat[i]>=3 && seat[i]<=6)
            mplace=false;
            if(seat[i]>=5 && seat[i]<=8)
            rplace=false;
        }
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int,vector<int>>booked;
        int res=0;
        for(int i=0;i<reservedSeats.size();i++){
            booked[reservedSeats[i][0]-1].push_back(reservedSeats[i][1]-1);
        }
        int b=booked.size();
        res=(n-b)*2;

 for(auto it=booked.begin();it!=booked.end();it++){
            bool lplace=true,rplace=true,mplace=true;
            isPlace(it->second,lplace,rplace,mplace);
            if(mplace && lplace && rplace)res+=2;
            else if(!lplace && !rplace && mplace)res+=1;
            else if(lplace || mplace || rplace)res+=1;
 }
        return res;
}
};
