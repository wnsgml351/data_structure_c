#include "Postfix.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Calculator/Calculator.h"
#include "../Queue/Queue.h"
#include "../Stack/stack.h"

// 연산자의 우선순위를 판단한다 (정한다)
int GetOperatorPriority(char operator) {
    switch (operator) {
        case '(': return isp[LPAREN];
        case ')': return isp[RPAREN];
        case '+': return isp[PLUS];
        case '-': return isp[MINUS];
        case '/': return isp[DIVIDE];
        case '*': return isp[MULTIPLY];
        case '%': return isp[MODULO];
        default: return -1;
    }
}

// 현재 입력받은 문자가 숫자인가 띄어쓰기인가 연산자인가? 등 판단
int CheckToken(char token) {
    switch (token) {
        case '(': return LPAREN;
        case ')': return RPAREN;
        case ' ': return EOS;
        case '.': return DOT;
        case '+': case '-': case '*': case '/': case '%': return OPERAND;
        // 나머지는 전부 숫자라고 가정한다
        default: return NUMBER;
    }
}

// 중위식을 후위식으로 변환하는 함수
// exp: 전달받은 수식
char* ConvertToPostfix(char exp[]) {
    int length = strlen(exp);
    Stack stack; // 연산자를 저장할 스택 생성
    // 수식의 길이만큼의 최대 크기를 가지는 스택 생성
    StackInitalize(&stack, length);

    // 변환된 후위식을 저장하는 배열
    char* convertExp = (char*)calloc(length * 2 + 1, sizeof(char));
    int idx = 0; // 현재 수식의 index

    /*********** 후위식 변환 start ! ***********/
    for (int i = 0; i < length; ++i) {
        char token = exp[i]; // 현재 문자
        // 문자가 어떤 형태인지 판단한다
        switch (CheckToken(token)) {
            case DOT: // . 이라면
            case NUMBER: // 숫자다
                // 후위식에 넣고 index를 증가시킴
                convertExp[idx++] = token;
                break;
            case EOS: // 띄어쓰기다
                break;
            case LPAREN: // 여는 괄호다
                // 여는 괄호는 우선순위가 가장 큼 무조건 PUSH
                pushChar(&stack, token);
                break;
            case RPAREN: // 닫는 괄호다
                // 여는 괄호가 나올때까지 스택에서 POP을 실행
                // POP된 요소들은 후위식에 추가
                while(true) {
                    char operator = popChar(&stack);
                    // 만약 뽑았는데 여는 괄호였다
                    if(CheckToken(operator) == LPAREN) {
                        break;
                    }
                    // 보기 좋으라고 띄어쓰기 하나 넣어줌
                    convertExp[idx++] = ' ';
                    // 수식에 연산자를 추가한다.
                    convertExp[idx++] = operator;
                }
                break;
            case OPERAND: // 계산을 해야 하는 연산자라면
                // Stack에 넣어야 하나? 후위식에 추가해야하나?
                // Stack에 다른 연산자가 있고
                // Stack에 있는 연산자와 비교해서 스택 연산자가 우선순위가 높다면
                while(!isStackEmpty(&stack) &&
                    GetOperatorPriority(peekChar(&stack)) >= GetOperatorPriority(token)) {
                    // 수식에 있는 연산자를 POP 해서 후위식에 추가해야한다
                    convertExp[idx++] = ' ';
                    convertExp[idx++] = popChar(&stack); // pop해서 추가
                }
                // 현재 토큰은 stack에 추가
                convertExp[idx++] = ' ';
                pushChar(&stack, token);
                break;
        }
    }

    // 수식 체크가 끝났는데 스택에 요소가 남아있다면
    // 연산자들이 아직 스택 안에 남아있다는 뜻
    // 모든 연산자들을 순서대로 후위식에 추가하면 끝!
    while(!isStackEmpty(&stack)) {
        convertExp[idx++] = ' ';
        convertExp[idx++] = popChar(&stack);
    }

    // 최종 후위식을 반환
    return convertExp;

}

void PostFixMain() {
    puts("====== PostFixMain ======");
    char exp1[] = "1 + 2 * 3";
    char exp2[] = "11*5+22";
    char exp3[] = "(1+2)*3";
    char exp4[] = "1.2+2.2+55";
    char exp5[] = "(1+2) * (3 + 5)";

    char* postfix1 = ConvertToPostfix(exp1);
    printf("변환 결과 : %s\n", postfix1);

    double result1 = Evaluation(postfix1);
    printf("계산 결과 %lf\n", result1);

    char* postfix2 = ConvertToPostfix(exp2);
    printf("변환 결과 : %s\n", postfix2);

    char* postfix3 = ConvertToPostfix(exp3);
    printf("변환 결과 : %s\n", postfix3);

    char* postfix4 = ConvertToPostfix(exp4);
    printf("변환 결과 : %s\n", postfix4);

    char* postfix5 = ConvertToPostfix(exp5);
    printf("변환 결과 : %s\n", postfix5);


}