#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;

    for (int a = 0; a <= d; a += k)
    {
        int ymax = sqrt(pow(d, 2) - pow(a, 2));
        answer += ymax / k + 1;
    }
    return answer;
}