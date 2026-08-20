class Solution {
public:
    vector<int> countBits(int n) {
        int count=0;
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int n=i;
         while(n!=0){
            n=n&(n-1);
              count++;
         }
         ans.push_back(count);
         count=0;
        }
        return ans;
    }
};