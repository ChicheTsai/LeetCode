char* addBinary(char* a, char* b) {
	char* ret;
	int lenA = strlen(a);
	int lenB = strlen(b);
	int lenC = ((lenA >= lenB) ? lenA : lenB) + 1;
	int x = lenA-1;
	int y = lenB-1;
	int z = lenC - 1;
	
	int result = 0, carry = 0, tmp;
	
	ret = (char*)malloc(sizeof(char) * (lenC + 1));
	ret[lenC] = '\0';
	
	while(x >=0 || y >=0)
	{
		tmp = carry;
		if(x >= 0)
		{
			tmp += (a[x] - '0');
		}
		if(y >= 0)
		{
			tmp += (b[y] - '0');
		}
		carry = (tmp >= 0x02) ? 0x01 : 0x00;
		if(carry)
		{
			tmp -= 0x02;
		}
		ret[z] = tmp + '0';
		z--;
		x--;
		y--;
	}
	
	if(carry)
	{
		ret[z] = 1 + '0';
	}
	else
	{		
		for(int i = 0; i < lenC; i++ )
		{
			ret[i] = ret[i + 1];
		}
	}
	
	return ret;
    
}