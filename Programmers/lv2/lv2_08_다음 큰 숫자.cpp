#include <string>
#include <vector>
#include <iostream>
using namespace std;

int CountZero(int n)
{
    int cnt = 1;
    while (n != 1)
    {
        if (n % 2 == 1)
            cnt++;
        n /= 2;
    }
    return cnt;
}

int solution(int n) {
    int cnt = CountZero(n);

    while (1)
    {
        n++;
        if (cnt == CountZero(n))
            break;
    }

    return n;
}