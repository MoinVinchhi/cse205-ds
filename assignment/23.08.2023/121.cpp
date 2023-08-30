class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int min_price = INT_MAX;
        int currProfit = 0;
        int profit = 0;

        for (auto x : prices){

            // if (x < min_price){
            //     min_price = x;
            // }]
            min_price = min(min_price, x);

            currProfit = x - min_price;
            
            // if (currProfit > profit){
            //     profit = currProfit;
            // }
            profit = max(profit, currProfit);
        }

        return profit;
    }
};