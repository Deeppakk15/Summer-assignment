class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        unordered_map<string,int>mp;
        int left=0;
        int right=0;
        int count=0;
        while(right<s.length()){
            if(s[right]=='1'){
                count++;
            }
            while(count==k){
                string temp=s.substr(left,right-left+1);
                mp[temp]=right-left+1;    
                if(s[left]=='1'){
                    count--;
                }
                left++;
            }
            right++;
        }
      if(mp.empty()) return "";

string ans="";
int minlength=INT_MAX;
for(auto it:mp){
if(it.second<minlength){
    minlength=it.second;
    ans=it.first;   
}
if(it.second==minlength && it.first<ans){
ans=it.first;
}
}

return ans;
    }
};