bool canConstruct(char* ransomNote, char* magazine) {
	int lenS1 = strlen(ransomNote);
	int lenS2 = strlen(magazine);
	
	if(lenS1 > lenS2)
	{
		return false;
	}
	else
	{
		int tab1[26] = {0};
		int tab2[26] = {0};
		
		for(int i = 0; i < lenS1; i++)
		{
			tab1[ransomNote[i] - 'a']++;
		}
		for(int i = 0; i < lenS2; i++)
		{
			tab2[magazine[i] - 'a']++;
		}
		
		for(int i = 0;i < 26; i++)
		{
			if(tab1[i] > tab2[i])
			{
				return false;
			}
		}
		return true;		
	}    
}