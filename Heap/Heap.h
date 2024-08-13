#ifndef HEAP_H
#define HEAP_H
#define HEAP_LENGTH 100 // Heap 데이터의 최대 개수

// d1 > d2 라면 0보다 큰 값을 반환 (양수)
// d1 == d2 라면 0을 반환
// d1 < d2 라면 0보다 작은 값을 반환 (음수)
typedef int PrioryComp(char d1, char d2);
typedef struct _heap {
    PrioryComp* comp;
    int numOfData; // 힙이 저장하고 있는 데이터 개수
    char heapArr[HEAP_LENGTH]; // 힙 자체 실제 데이터를 저장함
} HEAP;

#endif //HEAP_H
