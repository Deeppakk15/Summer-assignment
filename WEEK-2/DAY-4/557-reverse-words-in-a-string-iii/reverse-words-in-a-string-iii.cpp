class Solution {
public:
    string reverseWords(string s) {
    int first=0;
    int last=0;
   for(int last=0;last<=s.length();last++){
    if(s[last]==' ' || last ==s.length()){
        reverse(s.begin()+first,s.begin()+last);
        first=last+1;
    }
   }
   return s;
    }
   
};