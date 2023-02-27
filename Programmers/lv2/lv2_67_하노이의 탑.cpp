#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int A, int B, int C, vector<vector<int>>& answer)
{
    vector<int> tmp;
    if (n == 1)
    {
        tmp.push_back(A);
        tmp.push_back(C);
        answer.push_back(tmp);
    }
    else
    {
        hanoi(n - 1, A, C, B, answer);
        tmp.push_back(A);
        tmp.push_back(C);
        answer.push_back(tmp);
        hanoi(n - 1, B, A, C, answer);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;

    hanoi(n, 1, 2, 3, answer);

    return answer;
}