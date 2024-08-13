#ifndef POSTFIX_H
#define POSTFIX_H

// 계산이 가능한 연산자를 정의
typedef enum {
    LPAREN, // (
    RPAREN, // )
    PLUS, // +
    MINUS, // -
    MULTIPLY, // *
    DIVIDE, // /
    MODULO, // % (나머지)
    EOS, // ' '
    OPERAND, // 연산자인가
    NUMBER, // 숫자인가
    DOT // '.'
} OPERATOR;

// ( 는 ) 가 나올 때까지 계산되면 안되므로 연산 우선순위가 낮음
// ) 은 제일 먼저 계산 되어야 하므로 우선순위가 가장 높음
static int isp[] = {0, 99, 1, 1, 2, 2, 3};

#endif //POSTFIX_H
