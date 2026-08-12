class Solution {
void solve(vector<int>& candidates, vector<int>temp, vector<vector<int>>&ans, int i,int target){
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

//pick
temp.push_back(candidates[i]);
solve(candidates,temp,ans,i,target-candidates[i]);

//not pick
temp.pop_back();
solve(candidates,temp,ans,i+1,target);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        int index=0;
        solve(candidates,temp,ans,index,target);
        return ans;
    }
};