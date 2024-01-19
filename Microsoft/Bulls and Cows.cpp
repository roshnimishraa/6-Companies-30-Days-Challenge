class Solution {
public:
    string getHint(string secret, string guess) {
     vector<int> freq(10,0);
     string hint;
     int bulls=0, cows=0;
for(int i=0;i<secret.length();i++){
    if(guess[i] == secret[i]){
        bulls++;
    }
    else{
        if(freq[secret[i]-'0']++ < 0){
            cows++;
        }
        if(freq[guess[i]-'0']-- > 0){
            cows++;
        }
    }
}   
hint = to_string(bulls)+"A"+to_string(cows)+"B";
return hint;
    }
};
