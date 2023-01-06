#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
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