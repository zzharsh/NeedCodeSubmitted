class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0, j=0, n = prices.size();
        int profit = 0;
        while(j<n)
        {
            if(prices[j] > prices[i])
            {
                profit = max(profit, prices[j] - prices[i]);
                j++;
            }
            else
            {
                i = j;
                j++;
            }
        }
        return profit;
    }
};
