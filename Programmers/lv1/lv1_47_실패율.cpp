#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int, float> a, pair<int, float> b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector <pair<int, float>> failRate;

    for (int i = 1; i <= N; i++)
    {
        int a = 0;
        int b = 0;

        for (int j = 0; j < stages.size(); j++)
        {
            if (stages[j] == i)
                a++;
            if (stages[j] >= i)
                b++;
        }

        float rate = (b == 0) ? 0.0f : (float)a / b;

        failRate.push_back(make_pair(i, rate));
    }

    sort(failRate.begin(), failRate.end(), compare);

    for (int i = 0; i < failRate.size(); i++)
        answer.push_back(failRate[i].first);

    return answer;
}