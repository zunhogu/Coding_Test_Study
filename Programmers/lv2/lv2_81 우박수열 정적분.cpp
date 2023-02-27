#include <string>
#include <vector>
using namespace std;

void getSequence(int k, vector<int>& result)
{
    while (k > 1)
    {
        result.push_back(k);
        if (k % 2 == 0) k /= 2;
        else k = k * 3 + 1;
    }
    result.push_back(1);
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;

    vector<double> values;
    vector<int> seq;
    getSequence(k, seq);

    values.push_back(0.0);
    for (int i = 0; i < seq.size() - 1; i++)
        values.push_back(values[values.size() - 1] + (seq[i] + seq[i + 1]) / 2.0);

    for (int i = 0; i < ranges.size(); i++)
    {
        int start = ranges[i][0];
        int end = values.size() - 1 + ranges[i][1];

        if (start > end) answer.push_back(-1.0);
        else answer.push_back(values[end] - values[start]);
    }

    return answer;
}