class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        int n = nums.size();
        for(int i = 0; i<n; i++) map[nums[i]] = i;
        for(int i = 0; i<n; i++) {
            if(map.find(target-nums[i]) != map.end() && map[target-nums[i]] != i) {
                int a = i;
                int b = map[target-nums[i]];
                if(a < b) return {a,b};
                return {b,a};
            }
        }
        return {-1,-1};
    }
};
