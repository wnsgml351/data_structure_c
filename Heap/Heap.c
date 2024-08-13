#include "Heap.h"

#include <stdio.h>

// 65 == 'A', 66 == 'B'
// 숫자가 작아야 크다라고 판단 (오름차순 정렬하기 위해)
int compare(char d1, char d2) {
    if(d1 > d2) return -1;
    else if(d1 == d2) return 0;
    else return 1;
}

// 최초 힙 생성 (초기화)
void HeapInitialize(HEAP* heap, PrioryComp comp) {
    heap->numOfData = 0; // 현재 데이터는 0개
    heap->comp = comp;
}

// 부모 노드의 인덱스 == 자식 노드의 인덱스 / 2
int GetParentNodeIndex(int index) {
    return index / 2;
}

// 왼쪽 자식 노드의 인덱스 == 부모 노드의 인덱스 * 2
int GetLeftChildNodeIndex(int index) {
    return index * 2;
}

// 오른쪽 자식 노드의 인덱스 == 부모 노드의 인덱스 * 2 + 1
int GetRightChildNodeIndex(int index) {
    return index * 2 + 1;
}

// 높은 우선순위의 자식 인덱스를 가져온다 (index => parent index)
int GetHighPriorityChildIndex(HEAP* heap, int index) {
    int leftChildNodeIndex = GetLeftChildNodeIndex(index); // 왼쪽 자식 노드 index
    int rightChildNodeIndex = GetRightChildNodeIndex(index);  // 오른쪽 자식  노드 index

    // 자식 노드가 존재하지 않는다면 자식 노드가 존재하지 않음
    if(leftChildNodeIndex > heap->numOfData) {
        return 0;
    }
    else if(leftChildNodeIndex == heap->numOfData) { // 왼쪽 자식 노드가 마지막 노드라면
        return leftChildNodeIndex; // 왼쪽 자식 노드 인덱스를 가져옴
    }
    else { // 오른쪽 자식노드도 존재한다.
        // 왼쪽 자식과 오른쪽 자식의 우선순위를 비교해서 부모와 교체해야함
        if(heap->comp(heap->heapArr[leftChildNodeIndex], heap->heapArr[rightChildNodeIndex]) > 0) {
            // 부모와 왼쪽을 교체한다
            return leftChildNodeIndex;
        } else {
            return rightChildNodeIndex;
        }
    }
}

// 힙에 데이터를 추가
void HeapInsert(HEAP* heap, char data) {
    // 자식이 삽입되는 기본 위치(index). 마지막에 넣는다
    int index = heap->numOfData + 1;

    // 부모와 교체 작업을 반복한다
    // 내가 최상위 노드까지 이동될 수 있으므로 혹시 최상위 노드가 되었다면 그만
    while (index != 1) {
        int parentIndex = GetParentNodeIndex(index); // 부모 노드
        char parentData = heap->heapArr[parentIndex]; // 부모의 데이터를 가져온다
        // 추가한 자식과 부모 데이터를 비교해서 우선순위를 판단
        // 0보다 크다라고 한다면 d1 (data) > d2(parent) 이기 때문에 자식이 우선순위 높음
        if(heap->comp(data, parentData) > 0) {
            // 부모와 교체작업을 시행한다
            heap->heapArr[index] = parentData; // 내 자리에 부모 데이터를 넣는다
            index = parentData; // 부모의 인덱스만 내가 가져간다
        } else {
            // 만약 자식이 우선순위가 낮다면 아래에 위치해야함. 그게 자식의 위치임
            break;
        }
    }

    // 마지막에 남은 index가 내 위치. 해당 위치에 나를 넣는다
    heap->heapArr[index] = data;
    heap->numOfData++; // 추가가 완료되었으니까 총 개수 + 1
}



// 힙의 데이터를 삭제 => 삭제할때 가장 상위 데이터를 가져옴
char HeapDelete(HEAP* heap) {
    char data = heap->heapArr[1]; // 기존에 있던 루트 노드 데이터를 임시 저장
    char lastData = heap->heapArr[heap->numOfData]; // 마지막 노드 데이터
    int parentIndex = 1; // root 노드 index

    // 교체해야하는 자식 index를 가져온다
    int childIndex = GetHighPriorityChildIndex(heap, parentIndex);
    // childIndex == 0은 변경할 대상(자식노드)이 없다는 뜻
    while(childIndex != 0) {
        // 만약 마지막 노드의 우선순위가 변경해야하는 자식 우선순위보다 높다면
        // 여기는 데이터 자체로 비교하므로 데이터가 작은 친구가 위로 올라가야함 == 작을수록 우선순위 높음
        if(lastData < heap->heapArr[childIndex]) {
            break;
        }
        // 현재 부모 위치에 자식을 설정한다 (자식을 위로 올린다. 나는 내려감)
        heap->heapArr[parentIndex] = heap->heapArr[childIndex];
        parentIndex = childIndex; // 나는 자식 위치로 간다
        // 다음에 변경할 자식 노드 대상을 가져온다
        childIndex = GetHighPriorityChildIndex(heap, parentIndex);
    }

    // 가장 아래에 있던 데이터
    // 원래 아래에 있었던 데이터인 lastData를 해당 위치에 설정한다.
    heap->heapArr[parentIndex] = lastData;
    heap->numOfData--; // 삭제 총 개수 -1
    return data;
}

// 힙에 있는 모든 데이터를 삭제하면서 상위 데이터들을 순서대로 출력하기
void HeapPrint(HEAP* heap) {
    while(heap->numOfData != 0) {
        printf("%c\n", HeapDelete(heap));
    }
}

void HeapMain() {
    HEAP heap;
    HeapInitialize(&heap,compare);
    HeapInsert(&heap, 'A'); // 최고 우선순위 == 1
    HeapInsert(&heap, 'B'); // 2
    HeapInsert(&heap, 'C'); // 3
    printf("delete %c\n", HeapDelete(&heap));

    HeapInsert(&heap, 'D'); // 4
    HeapInsert(&heap, 'E'); // 5
    HeapInsert(&heap, 'F'); // 6
    HeapPrint(&heap);
}