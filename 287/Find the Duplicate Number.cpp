class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<bool> map(n+1, false);

        for(int i = 0; i< n; i++ )
        {
            if(map[nums[i]] == true)
            {
                return nums[i];
            }
            else
            {
                map[nums[i]] = true;
            }
        } 

        return -1;        
    }
};
