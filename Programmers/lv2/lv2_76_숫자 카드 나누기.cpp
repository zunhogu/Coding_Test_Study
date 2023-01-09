#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

bool check(vector<int>& array, int gcd)
{
    for (int i = 0; i < array.size(); i++)
        if (array[i] % gcd == 0) return false;
    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int gcdA = arrayA[0], gcdB = arrayB[0];

    for (int i = 1; i < arrayA.size(); i++)
        gcdA = gcd(gcdA, arrayA[i]);
    answer = check(arrayB, gcdA) == true && answer <= gcdA ? gcdA : answer;

    for (int i = 1; i < arrayB.size(); i++)
        gcdB = gcd(gcdB, arrayB[i]);
    answer = check(arrayA, gcdB) == true && answer <= gcdB ? gcdB : answer;

    return answer;
}