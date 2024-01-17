class Solution{   
public:
    string printMinNumberForPattern(string s){
        stack<int> st;
        string ans;
        int num = 1;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(ch == 'D')
            {
                st.push(num);
                num++;
            }
            else{
                st.push(num);
                num++;
            while(st.size() > 0){
             ans += to_string(st.top());
             st.pop();
            }
            }
        }
        st.push(num);
        while(st.size()>0){
           ans += to_string(st.top());
             st.pop();
        }
        return ans;
    }
};
