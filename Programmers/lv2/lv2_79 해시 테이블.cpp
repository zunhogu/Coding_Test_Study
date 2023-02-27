#include <string>
#include <vector>
using namespace std;

void swap(vector<int>& v1, vector<int>& v2)
{
    vector<int> tmp;
    tmp = v1;
    v1 = v2;
    v2 = tmp;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;

    for (int i = data.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (data[j][col - 1] > data[j + 1][col - 1])
                swap(data[j], data[j + 1]);
            else if (data[j][col - 1] == data[j + 1][col - 1])
            {
                if (data[j][0] < data[j + 1][0])
                    swap(data[j], data[j + 1]);
            }
        }
    }

    vector<int> result;
    for (int i = row_begin; i <= row_end; i++)
    {
        int sum = 0;
        for (int j = 0; j < data[i - 1].size(); j++)
            sum += data[i - 1][j] % i;
        result.push_back(sum);
    }

    for (int i = 0; i < result.size(); i++)
        answer ^= result[i];

    return answer;
}