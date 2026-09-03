class Solution {
    bool checkpallindrome(string &s ,int left,int right){
        while(left<=right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }
public:
    int countSubstrings(string s) {
      int count=0;
for(int i=0;i<s.length();i++){
    for(int j=i;j<s.length();j++){
   if(checkpallindrome(s,i,j)){
   count++;
   }
}
}
return count;
    }
};