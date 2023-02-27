#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {

    int minidx = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < arr[minidx])
            minidx = i;
    }

    arr.erase(arr.begin() + minidx);

    if (arr.size() == 0)
        arr.push_back(-1);

    return arr;

}