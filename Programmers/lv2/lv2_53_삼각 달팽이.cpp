#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> result;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < i + 1; j++)
            temp.push_back(-1);
        result.push_back(temp);
    }

    result[0][0] = 1;

    int row = 0;
    int col = 1;
    int action = 1;
    while (action)
    {
        switch (action)
        {
        case 1: // down
        {
            for (; col < n; col++)
            {
                if (result[col][row] != -1) break;
                result[col][row] = result[col - 1][row] + 1;
            }
            action = result[--col][++row] == -1 ? 2 : 0;
            break;
        }
        case 2: // right
        {
            for (; row <= col; row++)
            {
                if (result[col][row] != -1) break;
                result[col][row] = result[col][row - 1] + 1;
            }
            --row;
            action = result[--col][--row] == -1 ? 3 : 0;
            break;
        }
        case 3: // up
        {
            for (; col >= 0; col--, row--)
            {
                if (result[col][row] != -1) break;
                result[col][row] = result[col + 1][row + 1] + 1;
            }
            ++col;
            ++row;
            action = result[++col][row] == -1 ? 1 : 0;
            break;
        }
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            answer.push_back(result[i][j]);
    }

    return answer;
}