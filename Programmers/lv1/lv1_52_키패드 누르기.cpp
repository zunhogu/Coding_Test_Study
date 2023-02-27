#include <string>
#include <vector>
#include <math.h>

using namespace std;

float GetDistacne(int x1, int y1, int x2, int y2);

string solution(vector<int> numbers, string hand) {
    string answer = "";

    vector<pair<int, int>> coord;
    coord.push_back(make_pair(1, 0));  // 0
    coord.push_back(make_pair(0, 3));  // 1
    coord.push_back(make_pair(1, 3));  // 2
    coord.push_back(make_pair(2, 3));  // 3
    coord.push_back(make_pair(0, 2));  // 4
    coord.push_back(make_pair(1, 2));  // 5
    coord.push_back(make_pair(2, 2));  // 6
    coord.push_back(make_pair(0, 1));  // 7
    coord.push_back(make_pair(1, 1));  // 8
    coord.push_back(make_pair(2, 1));  // 9

    pair<int, int> leftPos = make_pair(0, 0);  // curr Left Pos
    pair<int, int> rightPos = make_pair(2, 0);  // curr Right Pos

    for (int i = 0; i < numbers.size(); i++)
    {
        int targetPosX = coord[numbers[i]].first;
        int targetPosY = coord[numbers[i]].second;

        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer += "L";
            leftPos.first = targetPosX;
            leftPos.second = targetPosY;
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer += "R";
            rightPos.first = targetPosX;
            rightPos.second = targetPosY;
        }
        else
        {
            int currLeftPosX = leftPos.first;
            int currLeftPosY = leftPos.second;

            int currRightPosX = rightPos.first;
            int currRightPosY = rightPos.second;

            float distanceL = GetDistacne(targetPosX, targetPosY, currLeftPosX, currLeftPosY);
            float distanceR = GetDistacne(targetPosX, targetPosY, currRightPosX, currRightPosY);

            string s;
            if (distanceL == distanceR)
                s = (hand == "right") ? "R" : "L";
            else
                s = distanceL > distanceR ? "R" : "L";

            answer += s;
            if (s == "R")
            {
                rightPos.first = targetPosX;
                rightPos.second = targetPosY;
            }
            else
            {
                leftPos.first = targetPosX;
                leftPos.second = targetPosY;
            }
        }
    }

    return answer;
}

float GetDistacne(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}