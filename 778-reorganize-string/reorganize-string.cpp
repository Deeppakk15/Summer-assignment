class Solution {
public:
    string reorganizeString(string s) {
        vector<int>freq(26,0);
        priority_queue<pair<int,char>>pq;

        for(int i=0;i<s.length();i++){
             freq[s[i]-'a']++;
        }

              
        for(int i=0; i<freq.size();i++){
            if(freq[i]>(s.length()+1)/2){
                return "";
            }
            if(freq[i]>0){
            pq.push({freq[i],'a'+i});
            }

        }
        string ans="";
        while(pq.size()>=2){
            pair<int,char>temp =pq.top();
            pq.pop();
            temp.first--;
            ans=ans+temp.second;

            pair<int,char>next =pq.top();
            pq.pop();
            next.first--;
            ans=ans+next.second; 


            if(next.first > 0)
            pq.push(next);

             if(temp.first > 0)
             pq.push(temp);

            }

           if(!pq.empty()){
            ans.push_back(pq.top().second);
           }

        return ans;

    }
};