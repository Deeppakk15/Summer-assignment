class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& nums) {
        unordered_set<string>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
queue<string>q;
q.push(begin);
int level=1;
while(!q.empty()){
int size=q.size();
while(size--){
 string word=q.front();
 if(word==end){
    return level;
 }
 q.pop();
for(int i=0;i<word.length();i++ ){
    char original=word[i];
 for(char ch='a';ch<='z';ch++){
       word[i]=ch;
     if(st.count(word)){
        q.push(word);
        st.erase(word);
     }
 }
 word[i]=original;
 }
}
level++;
}

return 0;
    }
};