class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int>st;
        int minelem=INT_MAX;
        int maxelem =INT_MIN;
        for(int i=0;i<nums.size();i++){
            minelem=min(minelem,nums[i]);
            maxelem=max(maxelem,nums[i]);
            st.insert(nums[i]);
        }

        int k=maxelem-minelem;

        vector<int>ans;
     
     for(int i=minelem+1;i<maxelem;i++){
        if(!st.count(i)){
            ans.push_back(i);
        }
     }
     return ans;
    }
};