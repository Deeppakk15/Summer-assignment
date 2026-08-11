class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n);
        vector<int>right(n);
        vector<int>result;
int product=1;
        for(int i=0;i<nums.size();i++){
        left[i]=product;
        product=product*nums[i];
        }
product=1;

        for(int i=n-1;i>=0;i--){
        right[i]=product;
        product=product*nums[i];
        }

       for(int i=0;i<n;i++){
        int mult=left[i]*right[i];
        result.push_back(mult);
       
        }
return result;
    }
};