#include <string>
#include <vector>
using namespace std;

bool isSame(int row, int col, int size, const vector<vector<int>>& arr, int& zeroCnt, int& oneCnt)
{
    int n = arr[row][col];
    for (int i = row; i < row + size; i++)
    {
        for (int j = col; j < col + size; j++)
        {
            if (arr[i][j] == n) continue;
            else return false;
        }
    }

    if (!n) zeroCnt++;
    else oneCnt++;

    return true;
}


void recursive(int row, int col, int size, const vector<vector<int>>& arr, int& zeroCnt, int& oneCnt)
{
    if (isSame(row, col, size, arr, zeroCnt, oneCnt)) return;
    else  // divide
    {
        if (size / 2 != 0)
        {
            recursive(row, col, size / 2, arr, zeroCnt, oneCnt);  // first quad
            recursive(row, col + size / 2, size / 2, arr, zeroCnt, oneCnt);  // second quad
            recursive(row + size / 2, col, size / 2, arr, zeroCnt, oneCnt);  // third quad
            recursive(row + size / 2, col + size / 2, size / 2, arr, zeroCnt, oneCnt); // fourth quad
        }
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    int zeroCnt = 0;
    int oneCnt = 0;
    recursive(0, 0, arr.size(), arr, zeroCnt, oneCnt);

    answer.push_back(zeroCnt);
    answer.push_back(oneCnt);

    return answer;
}