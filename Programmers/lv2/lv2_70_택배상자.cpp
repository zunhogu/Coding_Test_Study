#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> order) {
    queue<int> mainContainer;
    vector<int> secondContainer;

    for (int i = 1; i <= order.size(); i++)
        mainContainer.push(i);

    int index = 0;
    while (index < order.size())
    {
        if (mainContainer.front() == order[index])
        {
            mainContainer.pop();
            index++;
        }
        else
        {
            if (!secondContainer.empty() && secondContainer.back() == order[index])
            {
                secondContainer.pop_back();
                index++;
            }
            else
            {
                if (mainContainer.empty()) break;
                secondContainer.push_back(mainContainer.front());
                mainContainer.pop();
            }
        }
    }

    return index;
}