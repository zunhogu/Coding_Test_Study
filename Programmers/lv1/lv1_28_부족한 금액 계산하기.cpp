#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;

    long long totalPrice = 0;
    for (int i = 1; i <= count; i++)
        totalPrice += price * i;

    return totalPrice > money ? totalPrice - money : 0;
}