#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < places.size(); i++)
    {
        bool result = true;
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (places[i][j][k] == 'P')
                {
                    // distance 1
                    // top
                    if (j - 1 >= 0 && places[i][j - 1][k] == 'P')
                    {
                        result = false;
                        break;
                    }

                    // right
                    if (k + 1 < 5 && places[i][j][k + 1] == 'P')
                    {
                        result = false;
                        break;
                    }

                    // bottom
                    if (j + 1 < 5 && places[i][j + 1][k] == 'P')
                    {
                        result = false;
                        break;
                    }

                    // left
                    if (k - 1 >= 0 && places[i][j][k - 1] == 'P')
                    {
                        result = false;
                        break;
                    }

                    // distance 2
                    // top
                    if (j - 2 >= 0 && places[i][j - 2][k] == 'P' && places[i][j - 1][k] == 'O')
                    {
                        result = false;
                        break;
                    }

                    // right
                    if (k + 2 < 5 && places[i][j][k + 2] == 'P' && places[i][j][k + 1] == 'O')
                    {
                        result = false;
                        break;
                    }

                    // bottom
                    if (j + 2 < 5 && places[i][j + 2][k] == 'P' && places[i][j + 1][k] == 'O')
                    {
                        result = false;
                        break;
                    }

                    // left
                    if (k - 2 >= 0 && places[i][j][k - 2] == 'P' && places[i][j][k - 1] == 'O')
                    {
                        result = false;
                        break;
                    }

                    // top left
                    if (j - 1 >= 0 && k - 1 >= 0 && places[i][j - 1][k - 1] == 'P' && !(places[i][j - 1][k] == 'X' && places[i][j][k - 1] == 'X'))
                    {
                        result = false;
                        break;
                    }

                    // top right
                    if (j - 1 >= 0 && k + 1 < 5 && places[i][j - 1][k + 1] == 'P' && !(places[i][j - 1][k] == 'X' && places[i][j][k + 1] == 'X'))
                    {
                        result = false;
                        break;
                    }

                    // bottom left
                    if (j + 1 < 5 && k - 1 >= 0 && places[i][j + 1][k - 1] == 'P' && !(places[i][j + 1][k] == 'X' && places[i][j][k - 1] == 'X'))
                    {
                        result = false;
                        break;
                    }

                    // bottom right
                    if (j + 1 < 5 && k + 1 < 5 && places[i][j + 1][k + 1] == 'P' && !(places[i][j + 1][k] == 'X' && places[i][j][k + 1] == 'X'))
                    {
                        result = false;
                        break;
                    }
                }
                else continue;
            }
            if (!result) break;
        }
        answer.push_back(result);
    }

    return answer;
}