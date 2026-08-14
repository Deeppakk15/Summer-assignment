class Solution {
  bool  verify(string temp){
    int count=0;
    for(int i=0;i<temp.length();i++){
        if(temp[i]=='('){
            count++;
        }
        else{
            count--;
        }
        if(count<0){
            return false;
        }
    }
    return count==0;
  }

void solve( string temp, vector<string>&ans,int &n){
    if(temp.length()==2*n){
       if(verify(temp)){
        ans.push_back(temp);
       }
        return;
    }
 
      temp.push_back('(');
      solve(temp, ans, n) ;

      temp.pop_back();

       temp.push_back(')');
      solve(temp,ans, n);
}

public:
    vector<string> generateParenthesis(int n) {
        string temp="";
        vector<string>ans;
     solve(temp,ans,n);
     return ans;
    }
};