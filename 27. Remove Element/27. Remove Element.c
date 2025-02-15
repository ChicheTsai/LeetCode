int removeElement(int* nums, int numsSize, int val) {
	int l = 0, r = numsSize -1;
	while(l <= r )
	{
		if(nums[l] == val)
		{
			while(r >= 0 && nums[r] == val)
			{
				r--;
			}
			
			if(l <= r)
			{
				nums[l] = nums[r];
				l++;
				r--;
			}
		}
		else
		{
			l++;
		}
	}
	return l;
}