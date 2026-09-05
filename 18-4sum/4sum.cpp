class Solution {
      void solve(long long newtarget,vector<int>& nums,int left,int right, vector<vector<int>>&ans ,int first,int second){
        while(left<right){
            long long sum=nums[left]+nums[right];

            if(sum<newtarget){
                left++;
            }
            else if(sum>newtarget){
                right--;
            }
            else{
                while(left<right && nums[left]==nums[left+1]) left++;
                while(left<right && nums[right]==nums[right-1]) right--;
                ans.push_back({first,second,nums[left],nums[right]});
                left++;
                right--;
            }
        }
      }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
 int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size();j++){
              if(j>i+1 && nums[j]==nums[j-1]) continue;
              long long newtarget=(long long)target-(nums[i]+nums[j]);
              solve(newtarget,nums,j+1,n-1,ans,nums[i],nums[j]);
            }
        }
        return ans;
    }
};