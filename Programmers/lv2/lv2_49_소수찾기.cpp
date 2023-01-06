#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

void dfs(string n, string numbers, vector<int>& result)
{
    if (numbers == "") return;
    for (int i = 0; i < numbers.size(); i++)
    {
        string temp = n + numbers[i];
        string tmep2 = numbers.substr(0, i) + numbers.substr(i + 1, numbers.length());

        result.push_back(stoi(temp));
        dfs(temp, tmep2, result);
    }
}


int solution(string numbers) {
    int answer = 0;

    vector<int> result;
    set<int> primes;

    for (int i = 0; i < numbers.size(); i++)
        result.push_back((numbers[i] - 48));

    dfs("", numbers, result);

    for (int i = 0; i < result.size(); i++)
        if (isPrime(result[i])) primes.insert(result[i]);

    return primes.size();
}