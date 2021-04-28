class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int i, n = nums.size();
        for(i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
                return nums[i];
            
        }
        return nums[i];
    }
};
