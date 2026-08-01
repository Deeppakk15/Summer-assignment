class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int>temp(n,0);
        for(int i=0;i<arr.size();i++){
     if(i==n-1){
        temp[i] = -1;
    }else{
    int maxi=*max_element(arr.begin()+i+1,arr.end());
    temp[i]=maxi;
    }
        }
return temp;
    }
};