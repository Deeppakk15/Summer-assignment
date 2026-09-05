class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>leftlargest(n);
        vector<int>rightsmallest(n);
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
          maxi=max(maxi,nums[i]);
          leftlargest[i]=maxi;
        }
        int mini=INT_MAX;
          for(int i=n-1;i>=0;i--){
          mini=min(mini,nums[i]);
          rightsmallest[i]=mini;
        }
          for(int i=0;i<nums.size();i++){
           if( leftlargest[i]- rightsmallest[i]<=k) return i;
        }
        return -1;
    }
};