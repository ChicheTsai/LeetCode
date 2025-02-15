#define INVALID_VAL 0xFFFF
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int x = 0, y = 0, z = 0;
	int a, b;
	
	int tmpArr[m+n];
	while(x < m || y < n)
	{
		a = (x < m) ? nums1[x] : INVALID_VAL;
		b = (y < n) ? nums2[y] : INVALID_VAL;
		
		if(a != INVALID_VAL && b != INVALID_VAL)
		{
			if(a < b)
			{
				tmpArr[z] = a;
				x++;
			}
			else
			{
				tmpArr[z] = b;
				y++;
			}
			z++;
		}
		else if(a != INVALID_VAL)
		{
			tmpArr[z] = a;
			x++;
    		z++;
		}
		else if(b != INVALID_VAL)
		{
			tmpArr[z] = b;
			y++;
    		z++;
		}		
	}
	
	memcpy(nums1, tmpArr, sizeof(int) * (m+n));
    
}