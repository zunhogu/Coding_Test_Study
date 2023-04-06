#include <iostream>
#include <cmath>

int main()
{
    int T;
    std::cin>>T;
    while(T--)
    {
        int x, y, length, d, result;
        std::cin>>x>>y;

        length = y - x;
        d = sqrt(length);
        pow(d, 2) == length ? result = 2 * d -1 : result = 2 * d;
        if(length > d * d + d) result++;
        std::cout<<result<<"\n";
    }
}   