class Solution {
public:
    bool isValidSerialization(string preorder) {
        int vacancy = 1;
preorder+=',';
for(int i=0;i<preorder.size();i++){
// comma seperated values of nodes 
    if(preorder[i] !=',') continue;
// after visiting node decrease count by 1
    vacancy--;

    if(vacancy < 0) return false;
//if current node is not null that means it has two child
    if(preorder[i-1] != '#'){
        vacancy += 2;
    }
}
return vacancy == 0;
    }
};
