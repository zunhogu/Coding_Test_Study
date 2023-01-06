#include <string>
#include <vector>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    while (!priorities.empty())
    {
        int frontVal = priorities.front();

        bool out = true;
        for (int i = 1; i < priorities.size(); i++)
        {
            if (frontVal < priorities[i])
            {
                if (location == 0)
                    location = priorities.size() - 1;
                else
                    location -= 1;

                out = false;
                priorities.erase(priorities.begin());
                priorities.push_back(frontVal);

                break;
            }
        }

        if (out)
        {
            answer++;
            if (location == 0)
                break;
            priorities.erase(priorities.begin());
            location--;
        }

    }

    return answer;
}