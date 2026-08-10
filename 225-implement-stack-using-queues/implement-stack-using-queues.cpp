class MyStack {
    queue<int>q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
       q.push(x);
       int n=q.size();
        while(--n){
         int k =q.front();
         q.pop();
         q.push(k);
        }
    }
    
    int pop() {
       int k= q.front();
       q.pop();
        return k;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
           return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */