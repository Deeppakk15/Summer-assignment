class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return 0;
        }
        unordered_set<char>st;
        int left=0;
        int maxlength=INT_MIN;
        for(int right=0;right<s.length();right++){   
        while(st.find(s[right])!=st.end()){
            st.erase(s[left]);
             left++;
        }
        maxlength=max(maxlength,right-left+1);
            st.insert(s[right]);
            
        }
        return maxlength;
    }
};