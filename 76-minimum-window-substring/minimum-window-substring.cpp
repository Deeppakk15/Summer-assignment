class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()){
            return "";
        }
        unordered_map<char,int>reqmp;
        unordered_map<char,int>currentmp;

        for(int i=0;i<t.length();i++){
            reqmp[t[i]]++;
        }

int start=0;
int left=0;
int aval=0;
int minlength=INT_MAX;
int need=reqmp.size();
int right=0;
while(right<s.length()){
currentmp[s[right]]++;
if(reqmp.count(s[right]) && currentmp[s[right]]==reqmp[s[right]]){
aval++;
}

while(aval==need){
   if(right-left+1<minlength){
     minlength=right-left+1;
     start=left;
   }
     
currentmp[s[left]]--;
if(reqmp.count(s[left]) && currentmp[s[left]]<reqmp[s[left]]){
aval--;
}
left++;
}

right++;
}
if(minlength==INT_MAX) return "";
return s.substr(start,minlength);
    }
};