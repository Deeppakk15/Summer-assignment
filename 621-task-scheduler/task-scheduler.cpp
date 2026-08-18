class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>nums(26,0);
        int time=0;
      priority_queue<int>pq;
        for(int i=0;i<tasks.size();i++){
            nums[tasks[i]-'A']++;
        }

for(int i=0;i<nums.size();i++){
    if(nums[i]>0){
    pq.push(nums[i]);
    }
}


while(!pq.empty()){
    vector<int>temp;
for(int i=1;i<=n+1;i++){
    if(!pq.empty()){
     int freq=pq.top(); 
     pq.pop();
     freq--;
     temp.push_back(freq);
    }
}

for(int i=0;i<temp.size();i++){
    if(temp[i]>0){
        pq.push(temp[i]);
    }
}

if(!pq.empty()){
time =time+(n+1);
}
else{
    time=time+temp.size();
}
}
return time;
    }
};