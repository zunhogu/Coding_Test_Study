#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    // ������ ���� �޸𸮸� ���� �Ҵ����ּ���.

    long long num = n;
    int cnt = 0;
    while (1)
    {
        if (num == 0)
            break;
        num /= 10;
        cnt++;
    }

    int* answer = (int*)malloc(sizeof(int) * cnt);

    for (int i = 0; i < cnt; i++)
    {
        answer[i] = n % 10;
        n /= 10;
    }


    return answer;
}