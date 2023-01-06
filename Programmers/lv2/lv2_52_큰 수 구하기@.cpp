#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";

    int startIdx = 0;
    for (int i = 0; i < number.length() - k; i++)
    {
        int max = number[startIdx] - 48;
        int maxIdx = startIdx;
        for (int j = startIdx; j <= k + i; j++)
        {
            if (max < number[j] - 48)
            {
                max = number[j] - 48;
                maxIdx = j;
            }
        }
        answer += number[maxIdx];
        startIdx = maxIdx + 1;
    }

    return answer;
}