#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";

    string str1 = "";
    string str2 = "";
    int i = 0;
    int j = i;
    while (str2.length() < t * m)
    {
        str1 += i % n >= 10 ? i % n + 55 : i % n + 48;
        i /= n;
        if (i == 0)
        {
            i = j + 1;
            j = i;
            reverse(str1.begin(), str1.end());
            str2 += str1;
            str1 = "";
        }
    }

    for (int i = p; answer.length() < t; i += m)
        answer += str2[i - 1];

    return answer;
}