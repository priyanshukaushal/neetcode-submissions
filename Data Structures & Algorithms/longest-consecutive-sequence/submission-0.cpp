class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> map;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            map[nums[i]] = 1;
        }
        int ans = 0;
        for(int i = 0; i<n; i++) {
            int curr = nums[i];
            int length = 1;
            while(map.find(curr+1) != map.end()) {
                length++;
                curr++;
            }
            ans = max(ans,length);
        }
        return ans;
    }
};
