class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto num : nums) {
            map[num]++;
            if(map[num] >= 2) return true;
        }
        return false;
    }
};