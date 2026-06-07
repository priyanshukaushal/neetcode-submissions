class Solution {
public:
    int minElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l<r) {
            int mid = l+(r-l)/2;
            if(nums[mid] > nums[r]) l = mid+1;
            else r = mid;
        }
        return l;
    }
    int search(vector<int>& nums, int target) {
        int minE = minElement(nums);
        int l = 0;
        int r = minE-1;
        while(l <= r) {
            int mid = l+(r-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid] > target) r = mid-1;
            else l = mid+1;
        }
        l = minE;
        r = nums.size()-1;
        while(l <= r) {
            int mid = l+(r-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid] > target) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};
