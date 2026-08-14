class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string>st;
      
        unordered_set<string>st2;
        for(int i=0;i<words.size();i++){
            st.insert(words[i]);
        }

        for(int i=0;i<words.size();i++){
            string temp=words[i];
           
            for(int j=0;j<temp.length();j++){
                  string temp2="";
            for(int k=j;k<temp.length();k++){
                temp2=temp2+temp[k];
                if(temp2!=temp && st.count(temp2)){
                  st2.insert(temp2);
                }
            }
            }
        }
          vector<string>ans(st2.begin(),st2.end());
        return ans;
    }
};