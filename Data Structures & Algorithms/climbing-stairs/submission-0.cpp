class Solution {
public:
    int climbStairs(int n) {
        int currMinus1 = 1;
        int currMinus2 = 1;
        for(int i = 2; i<=n; i++) {
            int curr = currMinus1+currMinus2;
            currMinus2 = currMinus1;
            currMinus1 = curr;
        }
        return currMinus1;
    }
};
