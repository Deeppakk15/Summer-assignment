class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int product = 1;
        int zero = 0;
        int n = nums.size();

        vector<int> ans(n);

        for(int x : nums){
            if(x == 0)
                zero++;
            else
                product *= x;
        }

        for(int i = 0; i < n; i++){

            if(zero > 1){
                ans[i] = 0;
            }
            else if(zero == 1){

                if(nums[i] == 0)
                    ans[i] = product;
                else
                    ans[i] = 0;

            }
            else{
                ans[i] = product / nums[i];
            }
        }

        return ans;
    }
};