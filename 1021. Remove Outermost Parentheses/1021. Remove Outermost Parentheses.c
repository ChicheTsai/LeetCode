char* removeOuterParentheses(char* s) {
	int n = strlen(s);
	char newS[n+1];
	int leftCnt = 0x0;
	int wrIdx = 0x0;
	
	for(int i = 0;i < n;i++)
	{
		if(s[i] == '(' && leftCnt == 0x0)
		{
			leftCnt++;
		}
		else
		{
			if(s[i] == '(')
			{
				leftCnt++;
			}
			else
			{
				leftCnt--;
			}
			
			if(leftCnt > 0x0)
			{
				newS[wrIdx++] = s[i];
			}
		}
	}
	newS[wrIdx] = '\0';
	memcpy(s, newS, sizeof(char) * (n+1));
	return s;    
}