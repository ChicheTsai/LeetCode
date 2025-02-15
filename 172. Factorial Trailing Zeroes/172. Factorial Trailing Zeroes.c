int getQuantity(int n, int baseN)
{
	int x = 1;
	int ret = 0;
	while(x <= n)
	{
		x *= baseN; 
		ret += (n / x);
	}
	return ret;
}

int trailingZeroes(int n) {
    int numOfTwo = 0, numOfFive = 0;
    
    // numOfTwo = getQuantity(n,2);
	numOfFive = getQuantity(n,5);
	
	return numOfFive;
}