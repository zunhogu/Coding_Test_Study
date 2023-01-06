#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(string expression) {

    long long result = 0;

    vector<char> priority = { '*', '+', '-' };
    vector<long long> operand;
    vector<char> oper;

    int index = 0;
    for (int i = 0; i <= expression.length(); i++)
    {
        if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-' || expression[i] == '\0')
        {
            if (expression[i] != '\0')
                oper.push_back(expression[i]);
            operand.push_back(stoll(expression.substr(index, i)));
            index = i + 1;
        }
    }

    do {
        vector<long long> operandTmp = operand;
        vector<char> operTmp = oper;
        for (int i = 0; i < priority.size(); i++)
        {
            while (1)
            {
                int index = find(operTmp.begin(), operTmp.end(), priority[i]) - operTmp.begin();
                if (index == operTmp.end() - operTmp.begin()) break;
                else
                {
                    switch (priority[i])
                    {
                    case '*':
                        operandTmp[index] = operandTmp[index] * operandTmp[index + 1];
                        break;
                    case '+':
                        operandTmp[index] = operandTmp[index] + operandTmp[index + 1];
                        break;
                    case '-':
                        operandTmp[index] = operandTmp[index] - operandTmp[index + 1];
                        break;
                    }
                    operandTmp.erase(operandTmp.begin() + index + 1);
                    operTmp.erase(operTmp.begin() + index);
                }
            }
        }
        result = max(result, abs(operandTmp[0]));
    } while (next_permutation(priority.begin(), priority.end()));

    return result;
}