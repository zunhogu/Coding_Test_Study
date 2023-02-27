#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    bool fail = false;
    for (int i = 1; i < words.size(); i++)
    {
        if (words[i - 1][words[i - 1].length() - 1] != words[i][0])
            fail = true;

        if (find(words.begin(), words.begin() + i, words[i]) - words.begin() != i)
            fail = true;

        if (fail)
        {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }
    }

    if (answer.size() == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}