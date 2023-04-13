#include <iostream>

int main()
{
    int T;
    std::cin>>T;

    while(T--)
    {
        int a, b, val = 1;
        std::cin>>a>>b;
        

        b = !(b % 4) ? 4 : b % 4;
        while(b--) val *= a;
        std::cout << (val%10?val%10:10) << "\n";
    }
}   