class Solution {
public:
    void helper(vector<int> &nums, int i, int target, vector<int> &temp, set<vector<int>> &s) {
        if(target==0) {
            s.insert(temp);
            return;
        }
        if(target < 0 || i >= nums.size()) return;
        temp.push_back(nums[i]);
        helper(nums,i,target-nums[i],temp,s);
        temp.pop_back();
        helper(nums,i+1,target,temp,s);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        set<vector<int>> s;
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums,0,target,temp,s);
        for(auto v : s) ans.push_back(v);
        return ans;
    }
};
