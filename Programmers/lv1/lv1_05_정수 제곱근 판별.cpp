#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long solution(long long n) {
    long long answer = 0;

    double x = sqrt(n);

    bool isdigit = (x - (int)x == 0) ? true : false;

    if (isdigit)
        answer = pow(x + 1, 2);
    else
        answer = -1;


    return answer;
}