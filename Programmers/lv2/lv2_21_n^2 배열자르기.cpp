#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> temp;

    for (long long i = left; i <= right; i++)
    {
        if (i % n < i / n + 1)
            temp.push_back(i / n + 1);
        else
            temp.push_back(i % n + 1);
    }

    return temp;
}
