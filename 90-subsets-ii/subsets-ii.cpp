class Solution {
void solve(vector<int>& nums, vector<int>temp,int i, vector<vector<int>>&ans){
    if(i==nums.size()){
    ans.push_back(temp);
    return;
}

temp.push_back(nums[i]);
     solve( nums,temp,i+1,ans);

     temp.pop_back();

     int j=i+1;
     while(j<nums.size()&& nums[j]==nums[i]){
        j++;
     }
      solve(nums,temp,j,ans);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
       sort(nums.begin(),nums.end());
        int i=0;
        solve(nums,temp,i,ans);
        return ans;
    }
};