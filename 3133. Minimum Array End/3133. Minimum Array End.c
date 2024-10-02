
long long minEnd(int n, int x) {
	long long ret = x;
	int tmp = x;
	int shift = 0;
	long long m = n -1;
	
	while(m)
	{
		if(!(tmp & 0x01))
		{
			ret |= ((m & 0x01) << shift);
			m >>= 1;
		}
		tmp >>= 1;
		shift++;		
	}


	return ret;
}