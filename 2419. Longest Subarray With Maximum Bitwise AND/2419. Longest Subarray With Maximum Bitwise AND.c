int longestSubarray(int* nums, int numsSize) {
	int maxData = -1, currentLen, maxLen = -1;
	for(int i = 0; i < numsSize; i++)
	{
		if(nums[i] > maxData)
		{
			currentLen = 1;
			maxData = nums[i];
			maxLen = 1;
		}
		else if(nums[i] == maxData)
		{
			currentLen++;
		}
		else
		{
			if(currentLen > maxLen)
			{
				maxLen = currentLen;
			}
			currentLen = 0;
		}
	}
	
	if(nums[numsSize-1] == maxData)
	{
		if(currentLen > maxLen)
		{
			maxLen = currentLen;
		}
	}
	
	return maxLen;
    
}