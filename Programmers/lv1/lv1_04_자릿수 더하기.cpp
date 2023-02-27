#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int solution(int n) {
    int answer = 0;


    for (int i = 8; i >= 0; i--)
    {
        int m = n / pow(10, i);
        answer += m;

        n -= (m * pow(10, i));
    }


    return answer;
}