#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) { return to_string(a) + to_string(b) > to_string(b) + to_string(a); }

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), compare);

    for (int i = 0; i < numbers.size(); i++)
        answer += to_string(numbers[i]);

    if (answer[0] == '0') return "0";
    else return answer;
}