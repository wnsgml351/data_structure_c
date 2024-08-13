#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool StackInitalize(Stack* stack, int max) {
    stack->stk = calloc(max, sizeof(char));
    if(stack->stk == NULL) {return false;}
    stack->ptr = 0; // 현재 위치를 index 0 (바닥)을 가리키게 함
    stack->max = max; // 스택의 최대 용량을 결정
    return true;
}

bool pushChar(Stack* stack, char data) {
    if(isStackFull(stack)) {
        puts("Error: Stack이 가득 찼습니다...!");
        return false;
    }
    // 현재 보고 있는 스택의 위치(index 위치)에 데이터를 설정한다
    stack->stk[stack->ptr] = data;
    stack->ptr++; // 포인터 (index) +1 증가
    return true;
}

char popChar(Stack* stack) {
    if(isStackEmpty(stack)) {
        puts("Error: Stack이 비었습니다..!");
        return (char)false; // 0을 char 형으로 반환 == NULL 반환
    }

    char data = stack->stk[stack->ptr -1]; // 현재 위치의 데이터를 가져온다.
    stack->ptr--; // 포인터를 1 감소 시킴 (아래로 내려감)
    return data; // 가져온 데이터를 반환
}

// 현재 가장 상위에 있는 하나의 데이터를 확인만 하는 함수
char peekChar(Stack *stack) {
    if(isStackEmpty(stack)) {
        puts("Error: Stack이 비었습니다..!");
        return (char)false; // 0을 char 형으로 반환 == NULL 반환
    }

    return stack->stk[stack->ptr -1];
}

bool isStackEmpty(Stack* stack) {
    return stack->ptr <= 0; // ptr 포인터가 바닥에 있다는 뜻
}

// 스택이 가득차 있는지 확인
bool isStackFull(Stack* stack) {
    return stack->ptr >= stack->max;
}

void stackMain() {
    Stack stack;
    int max = 5;
    StackInitalize(&stack, max);

    puts("===== STACK PROGRAM =====");

    while(true) {
        int menu;
        char data; // 넣을 데이터
        puts("===== 메뉴를 선택하세요 =====");
        printf(" (1)PUSH / (2)POP / (3)PEEK / (4)END \n");
        scanf("%d", &menu);
        rewind(stdin); // 숫자 다음에 문자 받아야해서 입력 버퍼 비워줌
        switch (menu) {
            case 1:
                printf("PUSH 할 데이터를 입력하세요 >> ");
                scanf("%c", &data);
                pushChar(&stack, data);
                break;
            case 2:
                printf("[POP 시도..]\n");
                data = popChar(&stack);
                // 내부 데이터가 없었을시 NULL을 반환을 한다
                // NULL은 false 취급이다.
                if(data) {
                    printf("가져온 데이터 : %c\n", data);
                }
                break;
            case 3:
                printf("[PEEK 시도..]\n");
                data = peekChar(&stack);
                // 내부 데이터가 없었을시 NULL을 반환을 한다
                // NULL은 false 취급이다.
                if(data) {
                    printf("가져온 데이터 : %c\n", data);
                }
                break;
            case 4:
                puts("종료..");
                return;
        }
    }

}
