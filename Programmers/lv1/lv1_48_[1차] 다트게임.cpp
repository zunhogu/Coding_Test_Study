#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(string dartResult) {

    vector<int> scores;
    int j = 0;
    for (int i = 0; i < 3; i++)
    {
        string score = "";
        int sum = 0;
        for (; j < dartResult.length(); j++)
        {
            if (isdigit(dartResult[j]))
                score += dartResult[j];
            else
            {
                if (dartResult[j] == 'S')
                    sum = pow(stoi(score), 1);
                else if (dartResult[j] == 'D')
                    sum = pow(stoi(score), 2);
                else if (dartResult[j] == 'T')
                    sum = pow(stoi(score), 3);

                if (dartResult[j + 1] == '*')
                {
                    sum *= 2;
                    if (i > 0)
                        scores[i - 1] *= 2;
                    j++;
                }
                else if (dartResult[j + 1] == '#')
                {
                    sum *= -1;
                    j++;
                }

                scores.push_back(sum);

                j++;
                break;
            }
        }
    }

    return scores[0] + scores[1] + scores[2];
}