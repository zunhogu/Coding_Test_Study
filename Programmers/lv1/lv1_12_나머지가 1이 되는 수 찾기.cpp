#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {

    int i = 0;
    for (i = 1; i < n; i++)
    {
        if ((n % i) == 1)
            return i;
    }

    return i;
}