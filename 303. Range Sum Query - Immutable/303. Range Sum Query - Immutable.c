


typedef struct {
	int sum;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
	NumArray* ret = (NumArray*)malloc(sizeof(NumArray) * numsSize);
	
	ret->sum = nums[0];
	
	for(int i = 1;i < numsSize; i++)
	{
		((NumArray*)(ret + i))->sum = nums[i] + ((NumArray*)(ret + i - 1))->sum;
	}

	return ret;
}

int numArraySumRange(NumArray* obj, int left, int right) {
	int ret = ((NumArray*)(obj + right))->sum;
//	printf("%d %d ", left, right);
    if(left > 0x0)
	{
		int resultL = ((NumArray*)(obj + left - 1))->sum;
		ret -= resultL;
	}

//	printf("%d\n", ret);

	return ret;
}

void numArrayFree(NumArray* obj) {
	free(obj);    
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/