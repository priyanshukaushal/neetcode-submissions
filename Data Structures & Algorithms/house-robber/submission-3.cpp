class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int robPrev = nums[0];
        int notRobPrev = 0;

        for(int i = 1; i<n; i++) {
            int robCurr = notRobPrev+nums[i];
            int notRobCurr = max(robPrev,notRobPrev);
            robPrev = robCurr;
            notRobPrev = notRobCurr;
        }
        return max(robPrev,notRobPrev);
    }
};
