class Solution {
public:
    int helper(vector<int> &nums, int i, int canRob, vector<vector<int>> &dp) {
        if(i == nums.size()) return 0;
        if(dp[canRob][i] != -1) return dp[canRob][i];
        if(canRob == 0) return dp[canRob][i] = helper(nums,i+1,1,dp);
        return dp[canRob][i] = max(helper(nums,i+1,1,dp), helper(nums,i+1,0,dp)+nums[i]);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int> (n,-1)); 
        return helper(nums,0,1,dp);
    }
};
