#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) { return a > b; }

vector<int> solution(vector<string> operations) {
    vector<int> answer(2, 0);

    vector<int> max_heap;
    vector<int> min_heap;
    make_heap(max_heap.begin(), max_heap.end());
    make_heap(min_heap.begin(), min_heap.end(), compare);

    int size = 0;
    for (string str : operations)
    {
        string oper = str.substr(0, 1);
        string data = str.substr(2, str.size());

        if (oper == "I")
        {
            max_heap.push_back(stoi(data));
            push_heap(max_heap.begin(), max_heap.end());
            min_heap.push_back(stoi(data));
            push_heap(min_heap.begin(), min_heap.end(), compare);
            size++;
        }
        else if (!max_heap.empty() && oper == "D" && data == "1")
        {
            pop_heap(max_heap.begin(), max_heap.end());
            max_heap.pop_back();
            size--;
        }
        else if (!min_heap.empty() && oper == "D" && data == "-1")
        {
            pop_heap(min_heap.begin(), min_heap.end(), compare);
            min_heap.pop_back();
            size--;
        }
        if (size == 0)
        {
            while (!max_heap.empty()) max_heap.pop_back();
            while (!min_heap.empty()) min_heap.pop_back();
        }
    }

    if (!max_heap.empty() && !min_heap.empty())
    {
        answer[0] = max_heap.front();
        answer[1] = min_heap.front();
    }

    return answer;
}