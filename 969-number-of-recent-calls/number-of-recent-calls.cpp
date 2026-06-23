class RecentCounter {
    queue<int>myqueue;
public:
    RecentCounter() {
    }
    int ping(int t) {
    //   if(!myqueue.empty()|| t<3000) {
    //     myqueue.push(t);
    //   }
    // else{
       while(!myqueue.empty() && myqueue.front()<(t-3000)){
        myqueue.pop();
       }
        myqueue.push(t);
    // }
     return myqueue.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */