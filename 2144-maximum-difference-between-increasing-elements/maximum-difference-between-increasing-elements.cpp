class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxdif=-1;
        int minelem=INT_MAX;
        for(int i=0;i<nums.size();i++){
           minelem=min(minelem,nums[i]);
          if(nums[i]>minelem){
            maxdif=max(maxdif,nums[i]-minelem);
          }
        }
        return maxdif;
    }
};