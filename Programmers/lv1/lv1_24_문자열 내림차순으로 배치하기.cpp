#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";

    vector <char> str;
    for (int i = 0; i < s.length(); i++)
        str.push_back(s[i]);

    sort(str.begin(), str.end(), greater<char>());

    for (int i = 0; i < str.size(); i++)
        answer += str[i];

    return answer;
}