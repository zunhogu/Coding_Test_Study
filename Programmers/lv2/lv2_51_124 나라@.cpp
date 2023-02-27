#include <string>
#include <vector>
using namespace std;

string solution(int n) {
    string answer = "";

    int remain;
    while (n != 0)
    {
        remain = n % 3;
        n /= 3;
        if (remain == 0)
        {
            answer = "4" + answer;
            --n;
        }
        else
            answer = to_string(remain) + answer;
    }

    return answer;
}