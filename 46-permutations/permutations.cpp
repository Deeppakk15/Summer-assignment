class Solution {
 unordered_set<int>st;   
void solve(vector<int>& nums, vector<int>temp,vector<vector<int>>&ans){
if(temp.size()==nums.size()){
    ans.push_back(temp);
    return;
}


for(int i=0;i<nums.size();i++){

if(st.find(nums[i])==st.end()){
temp.push_back(nums[i]);
st.insert(nums[i]);
solve(nums,temp,ans);
st.erase(nums[i]);
temp.pop_back();
}
}
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(nums,temp,ans);
        return ans;
    }
};