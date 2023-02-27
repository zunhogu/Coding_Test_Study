#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int w = 0;
    int h = 0;
    for (int i = 0; i < sizes.size(); i++)
    {
        int a = max(sizes[i][0], sizes[i][1]);
        int b = min(sizes[i][0], sizes[i][1]);

        w = max(w, a);
        h = max(h, b);
    }

    return w * h;
}
