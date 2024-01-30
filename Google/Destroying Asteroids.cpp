class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
     sort(asteroids.begin(),asteroids.end());
    long mass1 = mass; 
   for(int it:asteroids)
   {
  if((long)it > mass1) return false;
  else
  mass1 += it;     
   }
   return true; 
    }
};
