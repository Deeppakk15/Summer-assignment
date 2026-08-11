class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
       vector<int>leftsum(n);
       vector<int>rightsum(n); 
       int sum=0;
for(int i=0;i<nums.size();i++){
   leftsum[i]=sum;
   sum=sum+nums[i];
}
sum=0;
for(int i=n-1;i>=0;i--){
rightsum[i]=sum;
sum=sum+nums[i];
}
for(int i=0;i<nums.size();i++){
    if(leftsum[i]==rightsum[i]){
        return i;
    }
}
return -1;
    }
};