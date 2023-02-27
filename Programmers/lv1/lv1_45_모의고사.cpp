#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> result;

    int supoja1[] = { 1, 2, 3, 4, 5 };
    int supoja2[] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int supoja3[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == supoja1[i % (sizeof(supoja1) / sizeof(int))])
            cnt1++;
        if (answers[i] == supoja2[i % (sizeof(supoja2) / sizeof(int))])
            cnt2++;
        if (answers[i] == supoja3[i % (sizeof(supoja3) / sizeof(int))])
            cnt3++;
    }

    result.push_back(cnt1);
    result.push_back(cnt2);
    result.push_back(cnt3);

    int max = *max_element(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] == max)
            answer.push_back(i + 1);
    }


    return answer;
}