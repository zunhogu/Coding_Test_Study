#include <string>
#include <vector>

using namespace std;

bool isPrime(int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

int solution(int n) {
    int count = 0;

    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
            count++;
    }

    return count;
}
