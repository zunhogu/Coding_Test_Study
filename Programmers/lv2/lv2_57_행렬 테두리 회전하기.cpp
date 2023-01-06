#include <string>
#include <vector>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    vector<int> matrix;
    for (int i = 1; i <= rows * columns; i++)
        matrix.push_back(i);

    for (int i = 0; i < queries.size(); i++)
    {
        int index1 = (queries[i][0] - 1) * columns + queries[i][1] - 1;
        int index2 = (queries[i][2] - 1) * columns + queries[i][3] - 1;
        int value = matrix[index1];

        int prevValue = matrix[index1 + columns];
        int curValue;
        int width = queries[i][3] - queries[i][1];

        // top
        for (int j = index1; j < index1 + width; j++)
        {
            curValue = matrix[j];
            value = min(value, matrix[j]);
            matrix[j] = prevValue;
            prevValue = curValue;
        }

        // right
        for (int j = index1 + width; j < index2; j += columns)
        {
            curValue = matrix[j];
            value = min(value, matrix[j]);
            matrix[j] = prevValue;
            prevValue = curValue;
        }

        // bottom
        for (int j = index2; j > index2 - width; j--)
        {
            curValue = matrix[j];
            value = min(value, matrix[j]);
            matrix[j] = prevValue;
            prevValue = curValue;
        }

        // left
        for (int j = index2 - width; j > index1; j -= columns)
        {
            curValue = matrix[j];
            value = min(value, matrix[j]);
            matrix[j] = prevValue;
            prevValue = curValue;
        }
        answer.push_back(value);
    }
    return answer;
}