#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int zeroCount = 0;
    int correctCount = 0;
    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
            zeroCount++;
        else
        {
            if (win_nums.end() != find(win_nums.begin(), win_nums.end(), lottos[i]))
                correctCount++;
        }
    }

    int rank;
    rank = (zeroCount + correctCount == 0) ? 6 : 7 - (zeroCount + correctCount);
    answer.push_back(rank);
    rank = (correctCount == 0) ? 6 : 7 - correctCount;
    answer.push_back(rank);

    return answer;
}