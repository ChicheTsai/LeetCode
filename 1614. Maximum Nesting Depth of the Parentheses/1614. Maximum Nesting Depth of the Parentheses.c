int maxDepth(char* s) {
    int currDepth = 0, maxDepth = 0;
	for(int i = 0; i < strlen(s); i++)
	{
		if(s[i] == '(')
		{
			currDepth++;
		}
		else if(s[i] == ')')
		{
			if(currDepth == 0x0)
			{
				// error case
			}
			
			if(currDepth > maxDepth)
			{
				maxDepth = currDepth;
			}
			currDepth--;
		}
	}
	return maxDepth;
}