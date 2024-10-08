typedef struct stack
{
    int count;
    char c[100];
} STACK;

bool push(struct stack* pX, char c)
{
    if(pX->count > 100)
    {
        return false;
    }
    else
    {
        pX->c[pX->count++] = c;
		return true;
    }
}

bool pop(struct stack* pX)
{
    if(pX->count == 0)
    {
        return false;
    }
    else
    {
        pX->count--;
		return true;
    }
}

int minLength(char * s){
    STACK x;
    int strLen = strlen(s);
	x.count = 0;
	for(int i = 0;i < strLen; i++)
	{
		if(x.count == 0x0)
		{
			push(&x, s[i]);
		}
		else if(s[i] == 'B' && x.c[x.count-1] == 'A')
		{
			pop(&x);
		}
		else if(s[i] == 'D' && x.c[x.count-1] == 'C')
		{
			pop(&x);
		}
		else
		{
			push(&x, s[i]);
		}
	}
	return x.count;


}