#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int n) {

    // solution array
    vector<long long> fac;
    fac.push_back(1);
    fac.push_back(1);

    for (int i = 2; i < n + 1; i++)
    {
        long long sol = fac[i - 1];
        sol *= i;
        fac.push_back(sol);
    }

    for (int i = 0; i < fac.size(); i++)
        cout << fac[i] << " ";

    long long count = 0;
    for (long long i = 0; i < n / 2 + 1; i++)
    {
        long long oneCount = n - i * 2;
        count += fac[oneCount + i] / (fac[oneCount] * fac[i]);
    }

    return count;
}