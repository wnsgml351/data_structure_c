#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

typedef struct {
    int max; // 스택의 최대 용량
    int num; // 현재 요소이ㅡ 개수
    int top; // 제윌 위 꼭대기(front)
    int bottom; // 제일 아래 바닥 (bottom)
    char* que; // 큐 첫 요소에 대한 포인터로 큐 자체를 의미함 (char 배열)
} Queue;

bool QueueInitalize(Queue* queue, int max);
bool enqueueChar(Queue* queue, char data);
char dequeueChar(Queue* queue);
char peekQueueChar(Queue *queue);
bool isQueueEmpty(Queue* queue);
bool isQueueFull(Queue* queue);
void queueMain();
#endif //QUEUE_H
