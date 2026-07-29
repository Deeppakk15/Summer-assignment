class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalprofit=0;
        for(int i=1;i<prices.size();i++){
          if(prices[i]>prices[i-1])  {
             int currntprofit= prices[i]-prices[i-1];
             totalprofit=totalprofit+currntprofit;
          }
        }
        return totalprofit;
    }
};