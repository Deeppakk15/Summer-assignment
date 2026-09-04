class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        vector<int>maxelemleft(n);
        vector<int>maxelemright(n);
        int sum=0;
         int maxi=0;
        for(int i=0;i<nums.size();i++){
           maxi=max(maxi,nums[i]);
           maxelemleft[i]=maxi;
        }
        maxi=0;
         for(int i=n-1;i>=0;i--){
           maxi=max(maxi,nums[i]);
           maxelemright[i]=maxi;
        }
       int ans=0;
        for(int i=0;i<nums.size();i++){
     ans=ans+(min(maxelemleft[i],maxelemright[i])-nums[i]);
        }
        return ans;
    }
};