#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {

    string answer = "";

    vector<pair<char, int>> score;
    score.push_back(make_pair('R', 0));
    score.push_back(make_pair('T', 0));
    score.push_back(make_pair('C', 0));
    score.push_back(make_pair('F', 0));
    score.push_back(make_pair('J', 0));
    score.push_back(make_pair('M', 0));
    score.push_back(make_pair('A', 0));
    score.push_back(make_pair('N', 0));

    for (int i = 0; i < survey.size(); i++)
    {
        int index = 0;
        if (choices[i] < 4)
        {
            for (; index < score.size(); index++)
            {
                if (score[index].first == survey[i][0])
                    break;
            }
            score[index].second += 4 - choices[i];
        }
        else if (choices[i] > 4)
        {
            for (; index < score.size(); index++)
            {
                if (score[index].first == survey[i][1])
                    break;
            }

            score[index].second += choices[i] - 4;
        }
    }

    for (int i = 0; i < score.size(); i += 2)
    {
        if (score[i].second > score[i + 1].second)
            answer += score[i].first;
        else if (score[i].second < score[i + 1].second)
            answer += score[i + 1].first;
        else
            answer += score[i].first < score[i + 1].first ? score[i].first : score[i + 1].first;
    }

    return answer;
}