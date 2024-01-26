class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
    //start = [startX,startY]   
    // target=[targetX,targetY]
    //cost (x2-x1)+(y2-y1)
 //special roads[i] = [x1,y1,x2,y2,cost] find min cost
 map<vector<int>,int> dist;//to store each dist;
 dist[start]=0;
// filter roads: cost more than manhatten of themselves
vector<vector<int>> filterRoads;
for(auto r : specialRoads)
{
    int a=r[0], b=r[1], c=r[2], d=r[3], cost=r[4];
//a,b.......c,d with edgecost as cost
if(cost < abs(a-c) + abs(b-d))
{
    filterRoads.push_back({a,b,c,d,cost});
    dist[{c,d}] = abs(start[0]-c) + abs(start[1]-d);

}
}
// Dijkstra to find the ans
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
pq.push({0,start[0],start[1]});
while(!pq.empty())
{
    auto it=pq.top();
    pq.pop();
int mdist = it[0];
int x = it[1];
int y = it[2];

for(auto it:filterRoads)
{
    int a=it[0];
    int b=it[1];
    int c = it[2];
    int d=it[3];
    int rcost=it[4]; //road cost

if(dist[{c,d}] > mdist + abs(x-a)+abs(y-b)+rcost)
{
    dist[{c,d}] = mdist+abs(x-a)+abs(y-b)+rcost;
    pq.push({dist[{c,d}], c,d});
}
}
}
int ans=abs(start[0]-target[0])+abs(start[1]-target[1]);
for(auto it:filterRoads)
{
    int tx = target[0], ty=target[1];
    int a=it[0], b=it[1], c=it[2], d=it[3], cost=it[4];
 ans = min(ans, dist[{c,d}] + abs(c-tx) + abs(d-ty));
    cout<<dist[{c,d}]<<"\n";
}
return ans;
    }
};
