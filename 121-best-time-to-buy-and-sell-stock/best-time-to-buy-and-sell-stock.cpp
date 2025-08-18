class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -prices[0];
        int notHold = 0;

        for (int i = 1; i < prices.size(); i++) {
            hold = max(hold, -prices[i]);
            notHold = max(notHold, hold + prices[i]);
        }
        return notHold;
    }
};