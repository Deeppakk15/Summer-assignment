class Solution {
void combination(int i,int &n,int k,vector<int>&temp,vector<vector<int>>&ans){

if(k==0){
    ans.push_back(temp);
    return;
}
if(i>n){
    return;
}

 temp.push_back(i);
   combination( i+1,n,k-1,temp,ans);

temp.pop_back();
    combination( i+1,n,k,temp,ans);
}
   
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;       
     combination(1,n,k,temp,ans);
     return ans;
    }
};