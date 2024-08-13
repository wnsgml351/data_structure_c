#ifndef CIRCLEQUEUE_H
#define CIRCLEQUEUE_H
#define QUEUE_LENGTH 4

#include <stdbool.h>

typedef struct {
    int num; // 현재 요소 개수
    int front; // 맨 앞 요소
    int rear; // 맨 뒷 요소
    int que[QUEUE_LENGTH]; // 링 버퍼 큐 자체이며 배열임 실제 데이터가 들어 있음
} CircleQueue;

bool CQInitialize(CircleQueue* queue);
bool EnqueueCQ(CircleQueue* queue, int data);
int DequeueCQ(CircleQueue* queue);
void PrintCQ(CircleQueue* queue);
bool isCQempty(CircleQueue* queue);
bool isCQFull(CircleQueue* queue);

#endif //CIRCLEQUEUE_H
