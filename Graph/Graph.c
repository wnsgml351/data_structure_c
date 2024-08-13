#include "Graph.h"

#include <stdio.h>
#include <stdlib.h>

#include "../Queue/Queue.h"
#include "../Stack/stack.h"

void BFS() {
    puts("===== BFS =====");

    char startNode = 'A'; // A부터 출발
    // 방문한 노드를 순서대로 저장함
    char* visitNodes = (char*)calloc(12, sizeof(char));
    int visitIndex = 0;
    // 큐를 정의 (방문할 후보 노드들을 저장하는 큐)
    Queue queue;
    QueueInitalize(&queue, 12);
    // 맨 처음 시작하는 노드를 후보에 넣고 시작
    enqueueChar(&queue, startNode);
    // 큐에 데이터가 없다 == 방문할 노드가 없다
    // 큐에 데이터가 있다면 노드를 방문한다
    while(!isQueueEmpty(&queue)) {
        // 후보 노드 중 맨 처음 노드를 꺼낸다
        char node = dequeueChar(&queue);
        printf("[%c]를 방문했습니다.\n", node);

        // 해당 노드를 방문했다라고 체크한다 (방문 배열에 넣음)
        visitNodes[visitIndex++] = node;
        // 그래프에서 방문한 노드의 연결 노드들을 가져오기 위해 index 추출
        int nodeIndex = (int)node - 65;
        // 후보 노드 배열을 순회한다
        int whileIndex = 0;
        puts("..후보로 추가..");
        while(graph[nodeIndex][whileIndex] != '\0') {
            printf("[%c] ", graph[nodeIndex][whileIndex]);

            enqueueChar(&queue, graph[nodeIndex][whileIndex]);
            whileIndex++;
        }
        puts("");
    }

    // 방문했던 노드들을 순서대로 출력
    puts("===== 방문했던 노드 =====");
    for (int i = 0; i < 12; ++i) {
        printf("%c ", visitNodes[i]);
    }





}


void DFS() {
    puts("===== DFS =====");

    char startNode = 'A'; // A부터 출발
    // 방문한 노드를 순서대로 저장함
    char* visitNodes = (char*)calloc(12, sizeof(char));
    int visitIndex = 0;
    // 큐를 정의 (방문할 후보 노드들을 저장하는 큐)
    Stack stack;
    StackInitalize(&stack, 12);
    // 맨 처음 시작하는 노드를 후보에 넣고 시작
    pushChar(&stack, startNode);
    // 큐에 데이터가 없다 == 방문할 노드가 없다
    // 큐에 데이터가 있다면 노드를 방문한다
    while(!isStackEmpty(&stack)) {
        // 후보 노드 중 맨 처음 노드를 꺼낸다
        char node = popChar(&stack);
        printf("[%c]를 방문했습니다.\n", node);
        // 해당 노드를 방문했다라고 체크한다 (방문 배열에 넣음)
        visitNodes[visitIndex++] = node;
        // 그래프에서 방문한 노드의 연결 노드들을 가져오기 위해 index 추출
        int nodeIndex = (int)node - 65;
        // 후보 노드 배열을 순회한다
        int whileIndex = 0;
        puts("..후보로 추가..");
        while(graph[nodeIndex][whileIndex] != '\0') {
            printf("[%c] ", graph[nodeIndex][whileIndex]);

            pushChar(&stack, graph[nodeIndex][whileIndex]);
            whileIndex++;
        }
        puts("");
    }

    // 방문했던 노드들을 순서대로 출력
    puts("===== 방문했던 노드 =====");
    for (int i = 0; i < 12; ++i) {
        printf("%c ", visitNodes[i]);
    }

}

int visitIndex = 0;

// 재귀를 사용한 DFS 탐색
// node: 현재 방문한 노드 / visit: 지금까지 방문했던 노드를 순서대로 저장
void recursion_DFS(char node, char visit[]) {
    printf("visit [%c]\n", node);
    visit[visitIndex++] = node; // 방문 리스트에 추가함
    int rowIndex = (int)(node) - 65;
    int colIndex = 0; // graph에서 현재 노드의 후보 노드 배열 탐색
    while(graph[rowIndex][colIndex] != '\0') {
        // 후보 중 하나를 즉시 방문
        recursion_DFS(graph[rowIndex][colIndex++], visit);
    }

}

void GraphMain() {
    char visit[12] = {};
    recursion_DFS('A', visit);

    puts("===== 방문했던 노드 =====");
    for (int i = 0; i < 12; ++i) {
        printf("%c ", visit[i]);
    }

}
