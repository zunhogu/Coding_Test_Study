#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num) {
    int answer = 0;

    long n = (long)num;
    while (n != 1)
    {
        if (answer > 500)
        {
            answer = -1;
            break;
        }

        if (n % 2 == 0)
            n /= 2;
        else
            n = n * 3 + 1;


        answer++;
    }

    return answer;
}