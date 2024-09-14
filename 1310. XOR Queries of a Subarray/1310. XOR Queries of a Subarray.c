/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
	int* pRet = (int*)malloc(sizeof(int) * queriesSize );
	int storeArray[arrSize];
	int startIdx, endIdx;
	*returnSize = queriesSize;
	
	storeArray[0] = arr[0];
	for(int i = 1; i < arrSize; i++)
	{
		storeArray[i] = storeArray[i - 1] ^ arr[i];
	}
	
	for(int i = 0; i < queriesSize; i++)
	{
		startIdx = queries[i][0];
		endIdx   = queries[i][1];
		pRet[i] = storeArray[endIdx];
		if(startIdx > 0)
		{
			pRet[i] ^= storeArray[startIdx - 1];
		}
	}
    
	return pRet;
}