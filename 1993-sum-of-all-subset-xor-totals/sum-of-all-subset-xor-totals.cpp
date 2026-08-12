class Solution {
int solvexor(vector<int>temp){
    int ans=0;
for(int i=0;i<temp.size();i++){
ans=ans^temp[i];
}
return ans;
}

void solve (vector<int>&nums,vector<int>&temp,int &sum,int i){
    if(i==nums.size()){
  int ans=solvexor(temp);
sum=sum+ans;
return;
    }

temp.push_back(nums[i]);
    solve (nums,temp,sum,i+1);
    temp.pop_back();
    solve (nums,temp,sum,i+1);
}


public:
    int subsetXORSum(vector<int>& nums) {
        vector<int>temp;
        int sum=0;
        int i=0;
        solve(nums,temp,sum,i);
        return sum;
    }
};