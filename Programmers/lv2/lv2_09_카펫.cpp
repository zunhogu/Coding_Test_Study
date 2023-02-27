#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> data;

    for (int i = 1; i <= yellow; i++)
    {
        if (yellow % i == 0)
            data.push_back(i);
    }

    int i = 0;
    int j = data.size() - 1;
    while (i <= j)
    {
        int sum = data[i] * 2 + data[j] * 2 + 4;
        if (brown == sum)
        {
            answer.push_back(data[j] + 2);
            answer.push_back(data[i] + 2);
            break;
        }

        i++;
        j--;
    }

    return answer;
}