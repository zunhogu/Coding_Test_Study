#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;

    int min = m >= n ? n : m;
    int max = m >= n ? m : n;

    int tmp = 0;
    while (min)
    {
        tmp = max % min;
        max = min;
        min = tmp;
    }

    answer.push_back(max);
    answer.push_back(n * m / max);

    return answer;
}