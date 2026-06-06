class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int n = prices.size();
        int ans = 0;

        for(int i = 0; i<n; i++) {
            if(minPrice < prices[i]) ans = max(ans,prices[i]-minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return ans;
    }
};
