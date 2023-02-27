#include <algorithm>
#include <string>

using namespace std;

// name[i]�� ������� ã�ٰ� 'A'�� ��찡 ������ 'A'�� �ƴҶ������� �ε��� ind�� ã�´�.
// �̶� i���� ind������ ���� ����� ���� ������ ����.
// 1. ���� -> i -> ���� ->(������) ind
// 2. ���� ->(������) ind -> ���� -> i
// �� �� ���� �ּҰ��� �����Ͽ� turn�� �ִ´�. 

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