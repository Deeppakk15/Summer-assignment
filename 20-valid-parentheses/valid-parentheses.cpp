class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char>mp;
        mp[')']='(';
        mp['}']='{';
        mp[']']='[';
     
stack<char>st;
for(int i=0;i<s.length();i++){
    if(s[i]==')'|| s[i]=='}'||s[i]==']'){
           if(!st.empty() && st.top()==mp[s[i]]){
            st.pop();
            continue;
           }
    }
    st.push(s[i]);
}
return st.empty();

    }
};