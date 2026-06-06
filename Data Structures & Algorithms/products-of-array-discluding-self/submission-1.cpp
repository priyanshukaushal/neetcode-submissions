class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<int> pre(n),suf(n);
        int prefix,suffix;
        prefix = suffix = 1;
        for(int i = 0; i<n; i++) {
            pre[i] = prefix;
            suf[n-1-i] = suffix;
            prefix *= nums[i];
            suffix *= nums[n-1-i];
        }
        for(int i = 0; i<n; i++) {
            ans.push_back(pre[i]*suf[i]);
        }
        return ans;
    }
};
