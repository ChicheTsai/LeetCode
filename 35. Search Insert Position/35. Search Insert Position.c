int searchInsert(int* nums, int numsSize, int target) {
	uint16_t l = 0, r = numsSize-1;
	uint16_t m = (l+r) / 2;
	int ret;

	/* [1,3,5,7,9] -> OK
	 * [1,3,5,7]
	 */
	
	if(target < nums[l])
	{
		return 0;
	}
	else if(target > nums[r])
	{
		return r + 1;
	}

	m = (l+r) / 2;
	
	while(l < r)
	{
		m = (l+r) / 2;
		if(nums[m] == target)
		{
			return m;
		}
		else if(nums[m] > target)
		{
			r = m - 1;
		}
		else if(nums[m] < target)
		{
			l = m + 1;
		}
	}

	if(l == r)
	{
		if(nums[l] == target)
		{
			return l;
		}
		else if(nums[r] < target)
		{
			return r + 1;				
		}
		else
		{
			return l;
		}
	}
	return m;
    
}