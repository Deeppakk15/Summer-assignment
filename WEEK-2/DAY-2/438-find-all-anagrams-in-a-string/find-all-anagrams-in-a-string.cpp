class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size()){
            return {};
        }
vector<int>ans;
       vector<int>freqS(26,0);
       vector<int>freqP(26,0);
       for(int i=0;i<p.size();i++){
        freqP[p[i]-'a']++;
       }
 int start=0;
 int end;
 int k=p.size();
 for(end=0;end<k;end++){
freqS[s[end]-'a']++;
 }
if(freqS==freqP){
ans.push_back(start);
}
for(int i=end;i<s.size();i++){
freqS[s[start]-'a']--;
start++;
freqS[s[i]-'a']++;
if(freqS==freqP){
    ans.push_back(start);
}
}
return ans;
  }
};