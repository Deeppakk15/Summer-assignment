class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mp;
        vector<string>temp;
        string ans="";
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
for(int i=0;i<arr.size();i++){
    if(mp[arr[i]] == 1){
  temp.push_back(arr[i]);
    }
}
for(int i=0;i<temp.size();i++){
    if(i==k-1){
ans=temp[i];
    }
}
return ans;
    }
};