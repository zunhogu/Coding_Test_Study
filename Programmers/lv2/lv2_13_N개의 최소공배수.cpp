#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    while (1)
    {
        answer++;

        int i = 0;
        for (; i < arr.size(); i++)
        {
            if (answer % arr[i] != 0)
                break;
        }
        if (i >= arr.size())
            break;
    }

    return answer;
}