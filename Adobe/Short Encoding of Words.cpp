class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
    //    unique words store in s1
        set<string> s1(words.begin(),words.end());
//    to store valid string 
    set<string> s2(words.begin(),words.end());
    
for(auto parts:s1){
    // find substrings of given string of words
    // eg. time =["ime","me","e"]
for(int i=1;i<parts.size();i++)
s2.erase(parts.substr(i));
}
int sum=0;
for(auto parts:s2){
sum += parts.size()+1;
}
return sum;
    }
};
