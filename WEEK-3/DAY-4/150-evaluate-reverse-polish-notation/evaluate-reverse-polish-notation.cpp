class Solution {
public:
    int evalRPN(vector<string>& tokens) {
     stack<int>st;
  for(int i=0;i<tokens.size();i++){
if(tokens[i]=="+"){
    int a =st.top();
    st.pop() ;
    int b=st.top();
    st.pop();
    st.push(a+b);
    continue;
}

if(tokens[i]=="-"){
    int a =st.top();
    st.pop();
    int b=st.top();
    st.pop();
    st.push(b-a);
    continue;
}
if(tokens[i]=="*"){
    int a =st.top();
    st.pop();
    int b=st.top();
    st.pop();
    st.push(a*b);
    continue;
}
if(tokens[i]=="/"){
    int a =st.top();
    st.pop();
    int b=st.top();
    st.pop();
    st.push(b/a);
    continue;
}
    st.push(stoi(tokens[i]));
      }
     return st.top();
    }
};