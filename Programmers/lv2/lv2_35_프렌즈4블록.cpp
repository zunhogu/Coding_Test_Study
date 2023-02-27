#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<string> board) {

    vector<vector<pair<char, bool>>> newBoard;
    for (int j = 0; j < n; j++)
    {
        vector<pair<char, bool>> temp;
        for (int i = m - 1; i >= 0; i--)
            temp.push_back(make_pair(board[i][j], false));
        newBoard.push_back(temp);
    }

    while (1)
    {
        bool isFinished = true;

        for (int i = 0; i < newBoard.size() - 1; i++)
        {
            for (int j = 0; j < newBoard[i].size() - 1; j++)
            {
                if (newBoard[i][j].first == newBoard[i][j + 1].first &&
                    newBoard[i][j].first == newBoard[i + 1][j].first &&
                    newBoard[i][j].first == newBoard[i + 1][j + 1].first
                    )
                {
                    if (i + 1 >= newBoard.size() || j + 1 >= newBoard[i].size() || j + 1 >= newBoard[i + 1].size())
                        break;

                    newBoard[i][j].second = true;
                    newBoard[i + 1][j].second = true;
                    newBoard[i][j + 1].second = true;
                    newBoard[i + 1][j + 1].second = true;

                    isFinished = false;
                }
            }
        }

        if (isFinished) break;

        for (int i = 0; i < newBoard.size(); i++)
        {
            for (int j = newBoard[i].size() - 1; j >= 0; j--)
            {
                if (newBoard[i][j].second == true)
                    newBoard[i].erase(newBoard[i].begin() + j);
            }
        }
    }

    int remainCnt = 0;
    for (int i = 0; i < newBoard.size(); i++)
        remainCnt += newBoard[i].size();

    return m * n - remainCnt;
}