#include "Calculator.h"

#include <stdlib.h>
#include <string.h>

#include "../Stack/DoubleStack.h"

// 계산 가능한 연산자들
char* operators[] = {"+", "-", "*", "%", "/"};

// 하나의 문자열(token)가 숫자인가 연산자인가
int CheckPostfixToken(char* token) {
    for (int i = 0; i < 5; i++) {
        // strcmp(문자열1, 문자열2) => 두 문자열이 같으면 0을 반환함
        if(strcmp(operators[i], token) == 0) {
            return i; // 연산자의 operator index를 반환
        }
    }

    // 연산자와 일치하는거 없으면 숫자
    return -1;
}

// 두 숫자를 받아서 연산자로 연산해서 결과를 반환
double Calculate(char operator, double num1, double num2) {
    switch (operator) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '/': return num1 / num2;
        case '*': return num1 * num2;
        case '%': return (int)num1 % (int)num2;
        default: return -999999; // 미등록 연산자
    }
}

// 후위식 수식을 받아서 계산하는 함수
double Evaluation(char exp[]) {
    DoubleStack stack;
    DoubleStackInitalize(&stack, strlen(exp));
    // strtok(exp, " ") => exp 문자열을 " " (띄어쓰기)를 기준으로 나눠주세요(split)
    // 그러면 배열에 6 2 / 3 - 4 2 * + " ["6", "2", "/" , "122", "-" ...]
    char *token = strtok(exp, " ");

    while(token) {
        // 하나의 토큰값(문자)가 연산자인가 숫자인가 판단
        int operatorIndex = CheckPostfixToken(token);

        // 현재 문자가 숫자라면
        if(operatorIndex == -1) {
            // atoi -> 문자열을 숫자로 형변환해주는 함수 (token이 문자열 "6"이니까)
            pushDouble(&stack, atof(token));
        } else {
            // 현재 token(문자)가 연산자였다

            // 스택에 push했던 마지막 숫자 2개를 가져와서 계산
            double num1 = popDouble(&stack);
            double num2 = popDouble(&stack);
            double result = Calculate(operators[operatorIndex][0], num2, num1);

            // 계산한 후에는 계산 결과를 다시 push 해야한다.
            pushDouble(&stack, result);
        }

        // 다음 token(문자)를 가져온다
        token = strtok(NULL, " ");
    }

    return popDouble(&stack); // 최종 계산 결과를 pop해서 가져온다

}