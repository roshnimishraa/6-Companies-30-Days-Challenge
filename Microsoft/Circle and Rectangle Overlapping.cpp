Brute Force Approach 

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

for(int i=x1;i<=x2;i++){
    for(int j=y1;j<=y2;j++){
// using formula (x-h)^2+(y-k)^2 <= r^2
int c1 = i-xCenter;
int c2 = j-yCenter;
if(c1*c1 + c2*c2 <= radius*radius){
    return 1;
}
}
}   
return 0;
    }
};

Optimize Approach

class Solution {
public:
    bool checkOverlap(int radius, int h, int k, int x1, int y1, int x2, int y2) {
        int dx,dy;
if(x1 > h){
dx = x1;
}
else if(x2 < h){
    dx = x2;
}
else{
    dx = h;
}

if(y1 > k){
    dy = y1;
}
else if(y2 < k) {
    dy = y2;
}
else{
    dy = k;
}
return (h-dx)*(h-dx) + (k-dy)*(k-dy) <= radius*radius;
    }
};
