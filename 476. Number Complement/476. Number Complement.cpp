class Solution {
public:
    int findComplement(int num) {
		int ret = 0, bit;
		for(int i = 0; num >0; i++)
		{
			bit = (num & 0x01) ^ 0x01;
			ret += (bit << i);
			num >>= 0x1;
		}

		return (int)ret;
        
    }
};