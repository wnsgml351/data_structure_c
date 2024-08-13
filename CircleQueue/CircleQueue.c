#include "CircleQueue.h"
#include <stdbool.h>
#include <stdio.h>

// 원형 큐를 초기화
bool CQInitialize(CircleQueue* queue) {
    queue->front = 0;
    queue->rear = 0;
    queue->num = 0;
    return true;
}

// Enqueue
bool EnqueueCQ(CircleQueue* queue, int data) {
    if(isCQFull(queue)) {
        puts("Error : CQ가 가득 찼습니다.");
        return false;
    }
    // 실제 데이터들의 배열에서 내가 보고있는 마지막위치 rear 자리에 데이터를 설정한다.
    queue->que[queue->rear] = data;
    queue->rear++;
    // 만약 마지막 요소의 index 위치가 배열의 마지막 index를 넘어갔다면
    // 다음 요소는 0번에 들어가야함!
    if(queue->rear == QUEUE_LENGTH) {
        queue->rear = 0;
    }
    queue->num++;
    return true;
}

// Dequeue
int DequeueCQ(CircleQueue* queue) {
    if(isCQempty(queue)) {
        puts("Error: CQ에 데이터가 없습니다.");
        return false;
    }
    // Queue 제일 먼저 들어간 데이터가 나와야 하므로,
    // 내가 보고 있는 첫번째 데이터를 가져온다
    int data = queue->que[queue->front];
    queue->que[queue->front] = 0; // 해당 위치에 데이터가 없게 한다.
    // front 자리에는 이제 데이터가 없으므로 다음 요소로 이동해야함
    queue->front++;
    if(queue->front >= QUEUE_LENGTH) {
        queue->front = 0; // 맨 앞으로 이동해야함
    }
    queue->num--; // 총 데이터 개수 -1
    return data;
}

// Print (원형 큐의 내부 모습 관찰)
void PrintCQ(CircleQueue* queue) {
    puts("====== Circle Queue ======");
    for (int i = 0; i < QUEUE_LENGTH; ++i) {
        printf("INDEX: [%d] / VALUE: [%d] \n", i, queue->que[i]);
    }
    puts("==============================");
}

// 원형큐가 비었는지 확인
bool isCQempty(CircleQueue* queue) {
    return queue->num == 0;
}

// 원형 큐가 가득 차 있는지 확인
bool isCQFull(CircleQueue* queue) {
    return queue->num == QUEUE_LENGTH;
}

void CircleQueueMain() {
    CircleQueue queue;
    CQInitialize(&queue);

    puts("===== CIRCLE QUEUE PROGRAM =====");

    while(true) {
        int menu;
        int data; // 넣을 데이터
        puts("===== 메뉴를 선택하세요 =====");
        printf(" (1)Enqueue / (2)Dequeue / (3)PRINT / (4)END \n");
        scanf("%d", &menu);
        rewind(stdin); // 숫자 다음에 문자 받아야해서 입력 버퍼 비워줌
        switch (menu) {
            case 1:
                printf("Enqueue 할 데이터를 입력하세요 >> ");
                scanf("%d", &data);
                EnqueueCQ(&queue, data);
            break;
            case 2:
                printf("[Dequqe 시도..]\n");
                data = DequeueCQ(&queue);
                // 내부 데이터가 없었을시 false 반환을 한다
                if(data) {
                    printf("가져온 데이터 : %d\n", data);
                }
            break;
            case 3:
                printf("[Print 시도..]\n");
                PrintCQ(&queue);
            break;
            case 4:
                puts("종료..");
            return;
        }
    }
}