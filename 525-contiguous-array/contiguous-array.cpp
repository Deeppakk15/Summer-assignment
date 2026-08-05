class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        int presum=0;
        mp[0]=-1;
        int maxlength=0;
        for(int i=0;i<nums.size();i++){
         if(nums[i]==1){
            presum+=1;
         }
         else{
            presum+=-1;
         }
       
       if(mp.count(presum)){
           int length=i-mp[presum];
        maxlength=max(maxlength,length);
       }
       else{
        mp[presum]=i;
       }
        }
        return maxlength;
    }
};