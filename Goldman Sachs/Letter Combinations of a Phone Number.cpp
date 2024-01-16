class Solution {
public:
void helper(int index,string str,string mapping[],string output,vector<string> &ans){
    if(index== str.length()){
    ans.push_back(output);
    return;
    }
    int number = str[index] -'0';
    string values = mapping[number];
for(int i=0;i<values.length();i++){
    output.push_back(values[i]);
    helper(index+1,str,mapping,output,ans);
    output.pop_back();
}

}
    vector<string> letterCombinations(string digits) {
          vector<string> ans;
          string output="";
string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
if(digits.length()==0){
    return ans;
}
helper(0,digits, mapping,output,ans);
return ans;
    }
};
