typedef struct NODE{
	int val;
	struct NODE* lower;
	struct NODE* upper;
} NODE_T;

typedef struct {
	NODE_T* top;
} MinStack;

MinStack* minStackCreate() {
	MinStack* node = (MinStack*)malloc(sizeof(MinStack));
	node->top = NULL;
	return node;    
}

void minStackPush(MinStack* obj, int val) {
	NODE_T* node = (NODE_T*)malloc(sizeof(NODE_T));
	node->val = val;
	node->upper = NULL;
	
	if(obj->top == NULL)
	{
		node->lower = NULL;
	}
	else
	{
		node->lower = obj->top;
		obj->top->upper = node;
	}	
	obj->top = node;
}

void minStackPop(MinStack* obj) {
	if(obj->top != NULL)
	{
		NODE_T* node = obj->top;
		if(node->lower)
		{
			obj->top = obj->top->lower;
			obj->top->upper = NULL;
		}
		else
		{
			obj->top = NULL;
		}
		free(node);
	}
}

int minStackTop(MinStack* obj) {
	if(obj->top != NULL)
	{
		return obj->top->val;
	}	
	return -1;
}

int minStackGetMin(MinStack* obj) {
	if(obj->top != NULL)
	{
		NODE_T* node = obj->top;
		int ret = node->val;
		while(node)
		{
			if(node->val < ret)
			{
				ret = node->val;
			}
			node = node->lower;
		}
		return ret;
	}
	else
	{
		return -1;
	}
}

void minStackFree(MinStack* obj) {
	NODE_T* node = obj->top;
	while(node)
	{
		obj->top = obj->top->lower;
		free(node);
		node = obj->top;		
	}  
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/