class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 3 == 0x0)
            {
                ans--;
            }
        }
        return ans;
        
    }
};