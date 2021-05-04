class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int i, j, n=prices.size(), dif=0;
        j = prices[0];
        for(i=1;i<n;i++)
        {
            
            if(prices[i] > j)
            {
                dif=max(dif, (prices[i] - j));
            }
            else
            {
                j = prices[i];
            }
            
        }
        
        return dif;
        
    }
};