int minBitFlips(int start, int goal) {
    int x = start ^ goal;
    int result = 0;
    while(x)
    {
        if(x & 0x01)
        {
            result++;
        }
        x >>= 1; 
    }
    return result;    
}