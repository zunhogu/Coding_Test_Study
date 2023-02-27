#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

bool isPrime(long long n)
{
    if (n <= 1) return false;

    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;

    string str = "";

    while (n != 0)
    {
        str += to_string(n % k);
        n /= k;
    }
    reverse(str.begin(), str.end());

    stringstream ss(str);
    string token;
    while (getline(ss, token, '0'))
    {
        if (token.length() != 0)
        {
            if (isPrime(stoll(token)))
                answer++;
        }
    }


    return answer;
}