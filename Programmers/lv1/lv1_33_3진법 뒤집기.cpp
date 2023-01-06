#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int solution(int n) {
    vector<int> arr;

    int a;
    while (!(n == 1 || n == 2))
    {
        a = n % 3;
        n /= 3;

        arr.push_back(a);
    }
    arr.push_back(n);

    int sum = 0;
    int cnt = 0;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        sum += arr[i] * pow(3, cnt);
        cnt++;
    }
    return sum;
}