#include <algorithm>
#include <string>

using namespace std;

// name[i]를 순서대로 찾다가 'A'의 경우가 나오면 'A'가 아닐때까지의 인덱스 ind를 찾는다.
// 이때 i에서 ind까지의 가는 방법의 수는 다음과 같다.
// 1. 원점 -> i -> 원점 ->(역주행) ind
// 2. 원점 ->(역주행) ind -> 원점 -> i
// 이 두 값중 최소값을 선택하여 turn에 넣는다. 

int solution(string name) {
    int answer = 0;
    int n = name.length();
    int turn = n - 1;
    for (int i = 0; i < n; i++) {
        if (name[i] - 'A' < 14) answer += name[i] - 'A';
        else answer += 'Z' - name[i] + 1;

        int ind = i + 1;
        while (ind < n && name[ind] == 'A') ind++;

        turn = min(turn, i + n - ind + min(i, n - ind));
    }

    answer += turn;
    return answer;
}