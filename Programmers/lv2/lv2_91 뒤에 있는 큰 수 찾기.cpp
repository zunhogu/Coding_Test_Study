#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    vector<bool> flags(numbers.size(), false);

    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (numbers[j] >= numbers[i])
                break;
            else
            {
                if (!flags[j])
                {
                    flags[j] = true;
                    answer[j] = numbers[i];
                }
            }
        }
    }

    return answer;
}