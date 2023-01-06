#include <string>
#include <vector>
#include <cmath>

using namespace::std;

long long get(int n)
{
    if (n == 1)
        return 0;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0 && n / i < 10000000)
            return n / i;
    }

    return 1;
}

vector<int> solution(long long begin, long long end) {

    vector<int> answer;

    for (int i = begin; i <= end; i++)
        answer.push_back(get(i));

    return answer;
}