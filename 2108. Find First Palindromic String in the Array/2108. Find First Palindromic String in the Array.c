char* firstPalindrome(char** words, int wordsSize) {
	char* s;
	int strLen;
	int x,y;
	bool flag = false;
	for(int i = 0;i < wordsSize; i++)
	{
		s = words[i];
		strLen = strlen(s);
		
		x = 0;
		y = strLen-1;
		flag = true;
		while(x <= y)
		{
			if(s[x] != s[y])
			{
				flag = false;
				break; 
			}
			x++;
			y--;
		}
		
		if(flag == true)
		{
			return s;
		}		
	}
	return "";
    
}