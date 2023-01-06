#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool isCorrectPos(int n, int row, int col, vector<int> board)
{
    int tmpCol, tmpRow;

    for (int i = 0; i < board.size(); i++)
    {
        if (board[i] == -1) continue;

        // same column
        if (board[i] == col)  return false;

        // left diag
        tmpCol = board[i];
        tmpRow = i;
        while (tmpCol >= 0 && tmpRow <= row)
        {
            if (tmpCol == col && tmpRow == row) return false;
            tmpCol--;
            tmpRow++;
        }

        // right diag
        tmpCol = board[i];
        tmpRow = i;
        while (tmpCol < n && tmpRow <= row)
        {
            if (tmpCol == col && tmpRow == row) return false;
            tmpCol++;
            tmpRow++;
        }
    }
    return true;
}

void dfs(int n, int row, vector<int> board, int& answer)
{
    if (row >= n) answer++;

    for (int i = 0; i < n; i++)
    {
        if (isCorrectPos(n, row, i, board))
        {
            board[row] = i;
            dfs(n, row + 1, board, answer);
        }
    }
}

int solution(int n) {
    int answer = 0;

    vector<int> board(n, -1);
    dfs(n, 0, board, answer);

    return answer;
}