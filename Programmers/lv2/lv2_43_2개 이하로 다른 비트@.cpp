#include <string>
#include <vector>
using namespace std;


vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); i++)
    {
        long long num = numbers[i];
        long long mask = 0;
        long long bit = 1;
        while (num & bit)
        {
            mask = ~bit;
            bit <<= 1;
        }
        num |= bit;
        if (mask != 0) num &= mask;

        answer.push_back(num);
    }

    return answer;
}