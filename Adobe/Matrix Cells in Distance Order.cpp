class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int row, int col, int rCenter, int cCenter) {
   int visited[row][col];
   for(int i=0;i<row;i++){
       for(int j=0;j<col;j++){
        visited[i][j] = 0;
       }
   }

  queue<pair<pair<int,int>,int>> q;
q.push({{rCenter, cCenter},0 });
  visited[rCenter][cCenter] = 1;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector<pair<int,pair<int,int>>> res;
vector<vector<int>> coord;
while(!q.empty()){
    auto p = q.front();
    q.pop();
    int x=p.first.first;
    int y = p.first.second;
    int dis = p.second;
    res.push_back({dis,{x,y}});
    for(int k=0;k<4;k++)
    {
        int xnew = x+dx[k];
        int ynew=y+dy[k];

if(xnew>=0 && xnew<row && ynew>=0 && ynew<col && visited[xnew][ynew]==0){
    q.push({{xnew,ynew},dis+1});
    visited[xnew][ynew]=1;
}
}
}
sort(res.begin(),res.end());
for(int i=0;i<res.size();i++){
    vector<int> temp(2,0);
    temp[0] = res[i].second.first;
    temp[1] = res[i].second.second;
    coord.push_back(temp);
}
return coord;
    }
};
