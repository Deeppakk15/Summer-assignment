class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
       vector<int>ans(n) ;

       for(int i=0;i<nums.size();i++){
            int mx=*max_element(nums.begin(),nums.begin()+i+1);
             int min=*min_element(nums.begin()+i,nums.begin()+n-1+1);
             ans[i]=mx-min;

       }

       for(int i=0;i<ans.size();i++){
        if(ans[i]<=k){
            return i;
        }
       }
       return -1;
    }
};