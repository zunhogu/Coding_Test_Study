#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* phone_number) {

    int len = strlen(phone_number);

    char* answer = (char*)malloc(sizeof(char) * len);

    strcpy(answer, phone_number);

    for (int i = len - 5; i >= 0; i--)
    {
        answer[i] = '*';
    }

    return answer;
}