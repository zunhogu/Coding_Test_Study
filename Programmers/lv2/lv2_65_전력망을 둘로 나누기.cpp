#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;

    for (int i = 0; i < wires.size(); i++)
    {
        int result = 0;
        vector<vector<int>> temp = wires;
        for (int j = 0; j <= 1; j++)
        {
            vector<int> visit;
            vector<int> stack;
            stack.push_back(temp[i][j]);

            while (!stack.empty())
            {
                int curr = stack.back();
                visit.push_back(curr);
                stack.pop_back();

                for (int k = 0; k < wires.size(); k++)
                {
                    if (k != i && wires[k][0] == curr)
                    {
                        if (find(visit.begin(), visit.end(), wires[k][1]) == visit.end())
                            stack.push_back(wires[k][1]);
                    }
                    if (k != i && wires[k][1] == curr)
                    {
                        if (find(visit.begin(), visit.end(), wires[k][0]) == visit.end())
                            stack.push_back(wires[k][0]);
                    }
                }
            }
            result = visit.size() - result;
        }
        answer = min(answer, abs(result));
    }
    return answer;
}