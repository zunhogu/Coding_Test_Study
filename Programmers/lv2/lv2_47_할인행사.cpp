#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    int day = 0;
    for (int i = 0; i < number.size(); i++)
        day += number[i];

    int index = 0;
    while (index <= discount.size() - day)
    {
        vector<int> temp = number;
        for (int i = index; i < index + day; i++)
        {

            int idx = find(want.begin(), want.end(), discount[i]) - want.begin();

            if (idx != want.end() - want.begin())
            {
                if (temp[idx] != 0)
                    temp[idx] -= 1;
            }
        }

        int result = 0;
        for (int i = 0; i < temp.size(); i++)
            result += temp[i];

        if (!result) answer++;

        index++;
    }

    return answer;
}