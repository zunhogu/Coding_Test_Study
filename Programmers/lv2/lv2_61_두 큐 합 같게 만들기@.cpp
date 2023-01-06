#include <string>
#include <vector>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    int idx1 = 0, idx2 = 0;
    long long sum1 = 0, sum2 = 0;
    int size = queue1.size();

    for (int i : queue1)
        sum1 += i;
    for (int i : queue2)
        sum2 += i;

    while (answer <= (size << 2))
    {
        if (sum1 < sum2)
        {
            sum1 += queue2[idx2];
            sum2 -= queue2[idx2];
            queue1.push_back(queue2[idx2++]);
        }
        else if (sum1 > sum2)
        {
            sum1 -= queue1[idx1];
            sum2 += queue1[idx1];
            queue2.push_back(queue1[idx1++]);
        }
        else if (sum1 == sum2)
            return answer;
        answer++;
    }

    return -1;
}