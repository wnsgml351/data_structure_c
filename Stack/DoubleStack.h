#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct {
    int max; // 스택의 최대 용량
    int ptr; // 스택의 맨 윗 꼭대기 현재 스택의 위치를 의미함
    double* stk; // 스택 첫 요소에 대한 포인터로 스택 자체를 의미함 (double 배열)
} DoubleStack;

bool DoubleStackInitalize(DoubleStack* stack, int max);
bool pushDouble(DoubleStack* stack, double data);
double popDouble(DoubleStack* stack);
double peekDouble(DoubleStack *stack);
bool isDoubleStackEmpty(DoubleStack* stack);
bool isDoubleStackFull(DoubleStack* stack);
void doubleStackMain();
#endif //STACK_H
