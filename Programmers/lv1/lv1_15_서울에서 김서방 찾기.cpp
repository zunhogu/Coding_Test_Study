#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    int i = 0;
    for (; i < seoul.size(); i++)
    {
        if (seoul[i] == "Kim")
            break;
    }

    answer = "�輭���� " + to_string(i) + "�� �ִ�";

    return answer;
}