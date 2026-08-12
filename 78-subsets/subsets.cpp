class Solution {
    void buildsubset(vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans,int i){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }

//inculde
temp.push_back(nums[i]);
buildsubset(nums,temp,ans,i+1);
//exclude
temp.pop_back();
buildsubset(nums,temp,ans,i+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        int i=0;
        buildsubset(nums,temp,ans,i);
        return ans;
    }
};