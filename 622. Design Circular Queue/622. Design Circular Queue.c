typedef struct {
	int size;
	int usedSize;
	int headIdx;
	int* arr; 
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return (obj->usedSize == 0x0)? true : false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return (obj->usedSize == obj->size)? true : false;
}

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue *obj = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));
	int *arr = (int*) malloc(sizeof(int) * k);
	obj->size = k;
	obj->usedSize = 0;
	obj->headIdx = 0;
	obj->arr = arr;
	return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if(myCircularQueueIsFull(obj))
	{
		return false;
	}
	else
	{
		int idx = obj->headIdx + obj->usedSize;
		if(idx >= obj->size)
		{
			idx -= obj->size;
		}
		obj->arr[idx] = value;
		obj->usedSize++;
		return true;
	}    
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if(obj->usedSize == 0x0)
	{
		return false;
	}
	else
	{
		obj->headIdx++;
		obj->usedSize--;
		
		if(obj->headIdx == obj->size)
		{
			obj->headIdx = 0x0;
		}
		return true;
	}     
}

int myCircularQueueFront(MyCircularQueue* obj) {
	return (obj->usedSize) ? obj->arr[obj->headIdx] : -1;
}

int myCircularQueueRear(MyCircularQueue* obj) {
	int idx = obj->headIdx + obj->usedSize - 1;
	
	if(myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	else if(idx >= obj->size)
	{
		idx -= obj->size;
	}
	return obj->arr[idx];
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj);    
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/