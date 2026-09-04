class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>mp;
        for(int i=0;i<order.length();i++){
          mp[order[i]]=i;
        }

        for(int i=0;i<words.size()-1;i++){
           string temp1=words[i];
           string temp2=words[i+1];
           int len=min(temp1.length(),temp2.length());
             int j=0;
           for(j;j<len;j++){
             if(mp[temp1[j]]>mp[temp2[j]]){
                return false;
             }
             if(mp[temp1[j]] < mp[temp2[j]]){
                    break;
                }
           }
           if(j==len && temp1.length()>temp2.length()){
            return false;
           }

        }
        return true;
    }
};