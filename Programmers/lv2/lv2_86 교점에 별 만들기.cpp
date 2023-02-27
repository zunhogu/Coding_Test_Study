#include <string>
#include <vector>
using namespace std;

const long long MAX_VALUE = 1000000000000000;

bool isInteger(float num)
{
    if (num - (long long)num == 0.0f) return true;
    else return false;
}

vector<string> solution(vector<vector<int>> line) {
    vector<pair<long long, long long>> crds;

    for (int i = 0; i < line.size(); i++)
    {
        for (int j = i + 1; j < line.size(); j++)
        {
            double x, y;
            double a = (long long)line[i][0] * line[j][1] - (long long)line[i][1] * line[j][0];

            if (a != 0.0f)
            {
                x = ((long long)line[i][1] * line[j][2] - (long long)line[i][2] * line[j][1]) / a;
                y = ((long long)line[i][2] * line[j][0] - (long long)line[i][0] * line[j][2]) / a;
                if (isInteger(x) && isInteger(y)) crds.push_back(make_pair((long long)x, (long long)y));
            }
        }
    }

    long long max_x = -MAX_VALUE, max_y = -MAX_VALUE, min_x = MAX_VALUE, min_y = MAX_VALUE;
    for (int i = 0; i < crds.size(); i++)
    {
        if (crds[i].first > max_x) max_x = crds[i].first;
        if (crds[i].first < min_x) min_x = crds[i].first;
        if (crds[i].second > max_y) max_y = crds[i].second;
        if (crds[i].second < min_y) min_y = crds[i].second;
    }

    string row = string(max_x - min_x + 1, '.');
    vector<string> answer(max_y - min_y + 1, row);
    for (int i = 0; i < crds.size(); i++) {
        long long x = crds[i].first, y = crds[i].second;
        answer[abs(y - max_y)][abs(x - min_x)] = '*';
    }
    return answer;
}