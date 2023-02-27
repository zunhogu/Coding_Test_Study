#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int storey) {
    int answer = 0;

    int size = to_string(storey).size();
    int num = 1;
    while (storey != 0)
    {
        int digit = pow(10, num);
        int val = storey % digit;

        if (val < 5 * digit / 10)
        {
            storey -= val;
            answer += val / (digit / 10);
        }
        else if (val > 5 * digit / 10)
        {
            storey += digit - val;
            answer += (digit - val) / (digit / 10);
        }
        else
        {
            if (storey % (digit * 10) > 5 * digit)
            {
                storey += digit - val;
                answer += (digit - val) / (digit / 10);
            }
            else
            {
                storey -= val;
                answer += val / (digit / 10);
            }
        }
        num++;
    }

    return answer;
}