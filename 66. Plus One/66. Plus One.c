/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	
	int* ret = (int*)malloc((digitsSize + 1) * sizeof(int));
	int c = 0, tmp = 0, idx1;
	ret[digitsSize] = digits[digitsSize-1]+1;
	c = ret[digitsSize] / 10;
	ret[digitsSize] = ret[digitsSize] % 10;
	
	for(int idx = digitsSize-2; idx >= 0; idx--)
	{
		idx1 = idx + 1;
		tmp = (c + digits[idx]);
		ret[idx1] = tmp % 10;
		c = tmp / 10;
	}
	
	if(c == 0)
	{
		*returnSize = digitsSize;
		for(int i = 0; i < digitsSize;i++)
		{
			ret[i] = ret[i + 1];
		}
	}
	else
	{
		*returnSize = digitsSize + 1;
		ret[0] = 1;
	}
	
	return ret;
}