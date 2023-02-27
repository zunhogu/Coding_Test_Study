#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    int a = s / n;
    int b = s % n;
    if (a)
    {
        for (int i = 0; i < n; i++)
            answer.push_back(s / n);
        while (b)
        {
            answer[n - 1]++;
            n--;
            b--;
        }
    }
    else answer.push_back(-1);

    return answer;
}