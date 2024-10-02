bool canArrange(int* arr, int arrSize, int k) {
	
	int record[k];
	int tmp;
	memset(record, 0, sizeof(int) * k);

	for(int i = 0;i< arrSize; i++)
	{
		tmp = arr[i];
		if(tmp < 0)
		{
			int x = -tmp;
			x = (x / k + 1) * k; 
			tmp += x;
		}
		record[tmp % k]++;
	}
	
	if(record[0] & 0x01)
	{
		return false;
	}
    else
	{
		int oddK = (k/2) ? 1 :0;
		for(int i = 1; i< (k/2) + oddK; i++)
		{
			if(record[i] != record[k-i])
			{
				return false;
			}
		}
		
		return true;
	}
}