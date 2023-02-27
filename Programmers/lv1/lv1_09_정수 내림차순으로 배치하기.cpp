#include <string>
#include <vector>
#include <math.h>
using namespace std;

long long solution(long long n) {

    vector<long long> answer;

    while (1)
    {
        if (n == 0)
            break;
        answer.push_back(n % 10);
        n /= 10;
    }

    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = i + 1; j < answer.size(); j++)
        {
            if (answer[i] < answer[j])
            {
                long long temp = answer[i];
                answer[i] = answer[j];
                answer[j] = temp;
            }
        }
    }

    long long result = 0;
    int cnt = 0;
    for (int i = answer.size() - 1; i >= 0; i--)
    {
        result += answer[i] * pow(10, cnt);
        cnt++;
    }

    return result;
}