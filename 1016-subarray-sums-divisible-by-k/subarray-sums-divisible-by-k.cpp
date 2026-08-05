class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int prefsum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
           prefsum=prefsum+nums[i];
           int rem=prefsum%k;
           if(rem<0){
            rem=rem+k;
           }
           if(mp.count(rem)){
            count=count+mp[rem];
           }
                  mp[rem]++;
        }
        return count;
    }
};