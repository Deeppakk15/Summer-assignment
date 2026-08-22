class Solution {
public:
    string sortString(string s) {

        vector<int>count(26, 0);

        for(char ch:s) {
        count[ch-'a']++;
        }
        string ans="";

        while(ans.size()<s.size()) {
            
            for(int i = 0; i < 26; i++) {
                if(count[i] > 0) {
                    ans+=char('a' + i);
                    count[i]--;
                }
            }
            for(int i=25;i>=0; i--) {
                if(count[i] > 0) {
                    ans += char('a'+i);
                    count[i]--;
                }
            }
        }
        return ans;
    }
};