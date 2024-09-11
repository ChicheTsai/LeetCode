char* reversePrefix(char* word, char ch) {
	int startIdx = 0, currentIdx = 0, endIdx;
	char tmp;
	for(currentIdx = 0; currentIdx < strlen(word); currentIdx++)
	{
		if(word[currentIdx] == ch)
		{
			endIdx = currentIdx;
			while(startIdx < endIdx)
			{
				tmp = word[startIdx];
				word[startIdx++] = word[endIdx];
				word[endIdx--] = tmp;
			}
			break;
		}
	}
	return word;
    
}