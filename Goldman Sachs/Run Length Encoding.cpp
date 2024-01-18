string encode(string s)
{     

int n = s.length();
int count = 1; 
string str="";
for(int i=0;i<n;i++){
    if(s[i] == s[i+1])
    {
        count++;
    }
    else{
        str += s[i] + to_string(count);
        count = 1;
    }
}
return str;
}     
 
