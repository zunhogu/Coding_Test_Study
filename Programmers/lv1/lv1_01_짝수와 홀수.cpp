#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int num) {
    // ������ ���� �޸𸮸� ���� �Ҵ����ּ���
    char* answer;

    if (num % 2 == 0)
    {
        answer = (char*)malloc(sizeof(char) * 4);
        answer = "Even";
    }
    else
    {
        answer = (char*)malloc(sizeof(char) * 3);
        answer = "Odd";
    }


    return answer;
}