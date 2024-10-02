
typedef struct {
	int val;
} CustomStack;

typedef struct {
	CustomStack* arr;
	int maxSize;
	int usedSize;
} BottomNode;

BottomNode stackInfo;

CustomStack* customStackCreate(int maxSize) {
	CustomStack* arr = (CustomStack*)malloc(sizeof(CustomStack) * maxSize);
	stackInfo.arr = arr;
	stackInfo.maxSize = maxSize;
	stackInfo.usedSize = 0;
	return arr;    
}

void customStackPush(CustomStack* obj, int x) {
	if(stackInfo.usedSize < stackInfo.maxSize)
	{
		// CustomStack* arr = (stackInfo.arr + stackInfo.usedSize);
		CustomStack* arr = (obj + stackInfo.usedSize);
		stackInfo.usedSize++;
		arr->val = x;
	}
}

int customStackPop(CustomStack* obj) {
	int ret = -1;
	if(stackInfo.usedSize > 0)
	{
		//CustomStack* arr = (stackInfo.arr + (stackInfo.usedSize - 1));
		CustomStack* arr = (obj + (stackInfo.usedSize - 1));
		stackInfo.usedSize--;
		ret = arr->val;
	}
	return ret;
}

void customStackIncrement(CustomStack* obj, int k, int val) {
	if(stackInfo.usedSize > 0)
	{
		CustomStack* arr;
		for(int i = 0; i < k && i < stackInfo.usedSize; i++ )
		{
			arr =  (obj + i);
			arr->val += val;
		}
	}    
}

void customStackFree(CustomStack* obj) {
	free(obj);
	stackInfo.arr = NULL;
	stackInfo.maxSize = 0x0;
	stackInfo.usedSize = 0x0;
    
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);
 
 * int param_2 = customStackPop(obj);
 
 * customStackIncrement(obj, k, val);
 
 * customStackFree(obj);
*/