class Solution {
void solve(vector<int>& candidates, vector<int>temp, vector<vector<int>>&ans,int i,int target){
     if(target==0){
        ans.push_back(temp);
        return;
    }
    if(i==candidates.size()){
        return;
    }
    if(target<0){
        return;
    }
   
temp.push_back(candidates[i]);
//include
solve(candidates,temp,ans,i+1,target-candidates[i]);

//exclude
temp.pop_back();

int j=i+1;
while(j<candidates.size() && candidates[j]==candidates[i]){
    j++;
}
solve(candidates,temp,ans,j,target);

}

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        int i=0;
        sort(candidates.begin(), candidates.end());
        solve(candidates,temp,ans,i,target);
        return ans;
    }
};