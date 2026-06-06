class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> map;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int num : nums) map[num]++;
        for(pair<int,int> p : map) {
            if(pq.size() < k) {
                pq.push({p.second,p.first});
            }
            else if(pq.top().first < p.second) {
                pq.pop();
                pq.push({p.second,p.first});
            }
        }
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
