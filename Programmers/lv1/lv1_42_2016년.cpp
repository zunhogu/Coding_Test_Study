#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";

    int dateCount = 0;

    int dateArr[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    for (int i = 0; i < a - 1; i++)
        dateCount += dateArr[i];
    dateCount += b;

    switch (dateCount % 7)
    {
    case 0:
        answer = "THU";
        break;
    case 1:
        answer = "FRI";
        break;
    case 2:
        answer = "SAT";
        break;
    case 3:
        answer = "SUN";
        break;
    case 4:
        answer = "MON";
        break;
    case 5:
        answer = "TUE";
        break;
    case 6:
        answer = "WED";
        break;
    }


    return answer;
}