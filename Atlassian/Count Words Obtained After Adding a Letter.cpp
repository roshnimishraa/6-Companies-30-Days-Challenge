class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> st;
for(auto it:startWords)
{
    sort(it.begin(),it.end());
    st.insert(it);
}
int count=0;
for(auto it:targetWords)
{
    for(int i=0;i<it.size();i++)
    {
string search = it.substr(0,i)+it.substr(i+1);
sort(search.begin(),search.end());
if(st.find(search) != st.end())
{
count++;
break;
}

    }
}
return count;
    }
};
