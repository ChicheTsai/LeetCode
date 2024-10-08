


typedef struct {
	int num;
	struct ProductOfNumbers* next;
} ProductOfNumbers;

ProductOfNumbers* productOfNumbersCreate() {
	ProductOfNumbers* node = (ProductOfNumbers*)malloc(sizeof(ProductOfNumbers));
	node->next = NULL;
	node->num = 0;
	return node;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
	ProductOfNumbers *prev = NULL, *curr = obj;
	ProductOfNumbers* node = (ProductOfNumbers*)malloc(sizeof(ProductOfNumbers));
	node->next = obj->next;
	node->num = num;
	obj->next = node;
	
	curr->next = node;
	obj->num++;
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
	ProductOfNumbers *prev = NULL, *curr = obj;
	int ret = 1;
	
	curr = obj->next;
	while(k > 0)
	{
		ret *= curr->num;
		curr = curr->next;
		k--;
		if(ret == 0x0)
		{
			break;
		}
	}
	return ret;
}

void productOfNumbersFree(ProductOfNumbers* obj) {
	ProductOfNumbers *prev = obj, *curr = obj;
	
	while(curr)
	{
		prev = curr;
		curr = curr->next;
		free(prev);		
	}    
}

/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);
 
 * int param_2 = productOfNumbersGetProduct(obj, k);
 
 * productOfNumbersFree(obj);
*/