bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
	
	if(target < matrix[0][0])
	{
		return false;
	}
	else if(target > matrix[matrixSize-1][*matrixColSize - 1])
	{
		return false;
	}
	else
	{
		int m = matrixSize, n = *matrixColSize;
		int l = 0, r = m * n - 1, mid;
		int x, y;
	
		while(l < r)
		{
			mid = (l + r) / 2;
			x = mid / n;
			y = mid % n;
			
			if(matrix[x][y] == target)
			{
				return true;
			}
			else if(matrix[x][y] < target)
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}			
		}

		mid = (l + r) / 2;
		x = mid / n;
		y = mid % n;


		if(matrix[x][y] == target)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}