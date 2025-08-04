class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min =prices[0];
        int maxproft=0;
        for(int i=0;i<prices.size();i++){
            int dayprice=prices[i];

            if(dayprice<min){
                min=dayprice;
            }
            else{
            int proft =dayprice -min;
            if(proft>maxproft)
            maxproft=proft;

            };
          

        }
        return maxproft;
    }
};