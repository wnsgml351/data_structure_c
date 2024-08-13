#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct {
    int max; // 스택의 최대 용량
    int ptr; // 스택의 맨 윗 꼭대기 현재 스택의 위치를 의미함
    char* stk; // 스택 첫 요소에 대한 포인터로 스택 자체를 의미함 (char 배열)
} Stack;

bool StackInitalize(Stack* stack, int max);
bool pushChar(Stack* stack, char data);
char popChar(Stack* stack);
char peekChar(Stack *stack);
bool isStackEmpty(Stack* stack);
bool isStackFull(Stack* stack);
void stackMain();
#endif //STACK_H
