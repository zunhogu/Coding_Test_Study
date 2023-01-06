#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{

    int round = 0;
    while (1)
    {
        round++;
        if ((a + 1) / 2 == (b + 1) / 2)
            break;

        a = (a + 1) / 2;
        b = (b + 1) / 2;
    }

    return round;
}