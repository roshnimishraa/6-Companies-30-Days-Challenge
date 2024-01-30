class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
vector<vector<int>> dist(n,vector<int>(n,INT_MAX));     
for(auto it:edges){
    int u = it[0];
    int v = it[1];
 dist[u][v] = it[2];
 dist[v][u] = it[2];
}

for(int i=0;i<n;i++){
    dist[i][i] = 0;
}
for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
{
    continue;
}
dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
        }
    }
}
int countcity=n;
int cityNo = -1;
for(int i=0;i<n;i++){
int count=0;
for(int j=0;j<n;j++){
    if(dist[i][j] <= distanceThreshold) count++;
}
if(count <= countcity){
    countcity = count;
    cityNo = i;
}
}
return cityNo;
    }
};
