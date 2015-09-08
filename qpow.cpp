#include <iostream>

#define NUM_BITS (sizeof(int) * 8) - 1

double fast_expo(int x, int y)
{
    int msb;
    for(msb = NUM_BITS; (y & (1 << msb)) == 0; msb--); 
    std::cout << "msb is " << msb << std::endl;

    double sum = x;
    for(int bit = msb-1; bit >= 0; bit--)
    {
        std::cout << "square" << std::endl;
        sum *= sum;
        if((y & (1 << bit)) != 0)
        {
            std::cout << "multiply" << std::endl;
            sum *= x;
        }
    }
    return sum;
}

int main()
{
    int num, expo;
    while(1)
    {
        std::cin >> num >> expo;
        if(num <= 0 || expo <= 0)
            break;
        std::cout << fast_expo(num, expo) << std::endl << std::endl;
    }
    return 0;
}
