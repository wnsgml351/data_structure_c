#include "Queue.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool QueueInitalize(Queue* queue, int max) {
    queue->que = calloc(max, sizeof(char));
    if(queue->que == NULL) {return false;}
    queue->num = queue->top = queue->bottom = 0;
    queue->max = max; // 큐의 최대 용량을 결정
    return true;
}

bool enqueueChar(Queue* queue, char data) {
    if(isQueueFull(queue)) {
        puts("Error: Queue이 가득 찼습니다...!");
        return false;
    }
    // 현재 보고 있는 스택의 위치(index 위치)에 데이터를 설정한다
    queue->que[queue->top] = data;
    queue->top++; // 포인터 (index) +1 증가
    queue->num++; // 큐에 현재 들어있는 개수 1 증가
    return true;
}

char dequeueChar(Queue* queue) {
    if(isQueueEmpty(queue)) {
        puts("Error: Queue이 비었습니다..!");
        return (char)false; // 0을 char 형으로 반환 == NULL 반환
    }

    // 제일 아래에 있는 데이터 가져오기
    char data = queue->que[queue->bottom];
    // 제일 아래 공간부터 바로 위에 있는 위치 데이터를 복사해온다
    for (int i = 0; i < queue->top - 1; ++i) {
        queue->que[i] = queue->que[i+1];
    }

    // 맨 위에 있는 데이터는 밑으로 한칸 내려갔으니까 NULL로 변경
    queue->que[queue->top - 1] = '\0'; // NULL
    queue->top--; // 내가 보고 있는 index 위치를 한칸 내림
    queue->num--; // 총 개수 -1

    return data; // 가져온 데이터를 반환
}

// 현재 가장 상위에 있는 하나의 데이터를 확인만 하는 함수
char peekQueueChar(Queue *queue) {
    if(isQueueEmpty(queue)) {
        puts("Error: Queue이 비었습니다..!");
        return (char)false; // 0을 char 형으로 반환 == NULL 반환
    }

    // 가장 아래에 있는 데이터를 반환
    return queue->que[queue->bottom];
}

bool isQueueEmpty(Queue* queue) {
    return queue->num <= 0; // ptr 포인터가 바닥에 있다는 뜻
}

// 스택이 가득차 있는지 확인
bool isQueueFull(Queue* queue) {
    return queue->num >= queue->max;
}

void queueMain() {
    Queue queue;
    int max = 5;
    QueueInitalize(&queue, max);

    puts("===== QUEUE PROGRAM =====");

    while(true) {
        int menu;
        char data; // 넣을 데이터
        puts("===== 메뉴를 선택하세요 =====");
        printf(" (1)Enqueue / (2)Dequeue / (3)PEEK / (4)END \n");
        scanf("%d", &menu);
        rewind(stdin); // 숫자 다음에 문자 받아야해서 입력 버퍼 비워줌
        switch (menu) {
            case 1:
                printf("Enqueue 할 데이터를 입력하세요 >> ");
                scanf("%c", &data);
                enqueueChar(&queue, data);
                break;
            case 2:
                printf("[Dequqe 시도..]\n");
                data = dequeueChar(&queue);
                // 내부 데이터가 없었을시 NULL을 반환을 한다
                // NULL은 false 취급이다.
                if(data) {
                    printf("가져온 데이터 : %c\n", data);
                }
                break;
            case 3:
                printf("[PEEK 시도..]\n");
                data = peekQueueChar(&queue);
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
