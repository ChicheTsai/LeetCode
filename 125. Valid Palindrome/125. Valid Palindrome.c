void getCharIdx(char* s, int len, int* idx, bool dir)
{
	if(dir == 0x0)
	{
		for(int i = *idx; i< len; i++)
		{
			if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') )
			{
				*idx = i;
				return;
			}
		}
		*idx = len;
	}
	else
	{
		for(int i = *idx; i >= 0; i--)
		{
			if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
			{
				*idx = i;
				return;				
			}
		}
		*idx = -1;
	}
}

bool getCompareResult(char* s, int l, int r)
{
	{
		char x = s[l];
		char y = s[r];

		if(s[l] >= 'A' && s[l] <= 'Z')
		{
			x = x - 'A' + 'a';
		}
	
		if(s[r] >= 'A' && s[r] <= 'Z')
		{
			y = y - 'A' + 'a';
		}
		
		return (x == y) ? true : false;
	}
}

bool isPalindrome(char* s) {
    int len = strlen(s);
	int l = 0, r = len - 1;
	int idxL, idxR;
	bool ret = true;
	while(l < r)
	{
		getCharIdx(s, len, &l, 0);
		getCharIdx(s, len, &r, 1);
		//printf("%c %c\n", s[l], s[r]);
		//printf("%d %d\n", l, r);
		if(l >= r)
		{
			return true;
		}
		else
		{	
			ret = getCompareResult(s, l, r);
			l++;
			r--;
			if(ret == false)
			{
				return false;
			}
		}
	}
	return true;
}