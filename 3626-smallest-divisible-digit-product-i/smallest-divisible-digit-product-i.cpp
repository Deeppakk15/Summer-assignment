class Solution {
public:
    int smallestNumber(int n, int t) {  
    while(true){
     int mult=1;
      int x=n;
      while(x>0){
     int digit =x%10;
     mult=mult*digit;
     x=x/10;
      }
      if(mult%t==0){
        break;
      }
      n++;
    }
    return n;
    }
};