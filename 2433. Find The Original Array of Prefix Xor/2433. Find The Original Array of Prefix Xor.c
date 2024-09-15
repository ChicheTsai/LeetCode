/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findArray(int* pref, int prefSize, int* returnSize) {
	
	int* ret = (int*)malloc(sizeof(int) * prefSize);
	*returnSize = prefSize;
    ret[0] = pref[0];
	for(int i = 1;i < prefSize; i++)
	{
		ret[i] = pref[i] ^ pref[i-1]; 
	}
	return ret;
}