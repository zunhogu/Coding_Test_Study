#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {

    int cnt = 0;
    vector<int> result;

    for (int i = 0; i < moves.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[j][moves[i] - 1] != 0)
            {
                result.push_back(board[j][moves[i] - 1]);
                board[j][moves[i] - 1] = 0;
                break;
            }
        }

        if (result.size() >= 2)
        {
            if (result[result.size() - 1] == result[result.size() - 2])
            {
                result.erase(result.begin() + result.size() - 1);
                result.erase(result.begin() + result.size() - 1);
                cnt += 2;
            }
        }
    }

    return cnt;
}