#include <iostream>

int main(int argc, char const *argv[])
{
    int cnt;
    double x1, y1, r1, x2, y2, r2;
    std::cin >> cnt;
    for(int i=0; i<cnt; i++)
    {
        double d;
        std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        d = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
        
        int c1 = (r1+r2) * (r1+r2);
        int c2 = (r1-r2) * (r1-r2);
        
        if(d == 0.0 && c2 == 0.0)
            std::cout << -1 << std::endl;
        else if(d == 0.0 && c2 != 0.0)
            std::cout << 0 << std::endl;
        else if(c1 == d || c2 == d)
            std::cout << 1 << std::endl;
        else if(c2 < d && c1 > d)
            std::cout << 2 << std::endl;
        else std::cout << 0 << std::endl;
    }
    return 0;
}