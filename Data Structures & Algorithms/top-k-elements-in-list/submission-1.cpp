class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> map;
        for(int num : nums) map[num]++;
        vector<vector<int>> buckets(nums.size()+1);
        for(pair<int,int> p : map) buckets[p.second].push_back(p.first);
        int i = nums.size();
        while(ans.size() < k) {
            if(buckets[i].size() == 0) i--;
            else {
                for(int num : buckets[i]) {
                    if(ans.size() == k) break;
                    ans.push_back(num);
                }
                i--;
            }
        }
        return ans;
    }
};
