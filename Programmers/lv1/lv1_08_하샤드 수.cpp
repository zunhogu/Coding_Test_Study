#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {

    int tmp = x;
    int sum = 0;
    while (1)
    {
        if (tmp == 0)
            break;
        sum += tmp % 10;
        tmp /= 10;
    }

    return x % sum == 0;
}