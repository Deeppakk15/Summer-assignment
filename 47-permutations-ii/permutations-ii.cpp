class Solution {
    unordered_map<int,int>mp;
    
 void solve(vector<int>&nums,vector<int>temp,vector<vector<int>>&ans){
if(temp.size()==nums.size()){
    ans.push_back(temp);
    return;
}

for(auto &it:mp){
    if(it.second>0){
        it.second--;
       temp.push_back(it.first);
        solve(nums,temp,ans);
        it.second++;
        temp.pop_back();
    }

}
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        for(int x:nums){
            mp[x]++;
        }
        solve(nums,temp,ans);
        return ans;
    }
};