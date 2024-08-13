#include "ChainHash.h"

#include <stdio.h>
#include <stdlib.h>

int Hasing(int key) {
    return key % 13;
}

void ChainHashInitialize(ChainHash *hash, int size) {
    // calloc(size, sizeof(ChainNode)); // 내용 데이터가 전부 초기화 되어있음 (NULL로)

    // ChainNode를 size 개수만큼 저장하는 table(배열)을 생성
    hash->table = (ChainNode**)(ChainNode*)calloc(size, sizeof(ChainNode));
    hash->size = size;
    for (int i = 0; i < size; ++i) {
        hash->table[i] = NULL;
    }
}

void ChainHashAddData(ChainHash* hash, int data) {
    // 추가하려는 데이터에 해싱 함수를 적용하여 추가할 위치를 도출함 === index
    int key = Hasing(data);
    // 해당 key 값의 해시테이블 노드를 가져온다
    ChainNode* node = hash->table[key];
    // 해당 위치에 노드가 있다면 그 노드와 연결된 마지막 노드까지 이동
    while(node != NULL) {
        if(node->data == data) {
            printf("Error: 이미 중복된 데이터가 존재합니다! [%d] \n", data);
            return;
        }
        node = node->nextNode;
    }

    // 만약 여기까지 왔다면 현재 node는 널일 것이다
    // 넣고 싶은 data를 가지는 Node를 생성한다
    ChainNode* newNode = (ChainNode*)calloc(1, sizeof(ChainNode));
    newNode->data = data;
    newNode->prevNode = NULL;
    newNode->nextNode = NULL;

    // 만약 내가 맨 첫노드가 아니라면 == 이미 해당 위치에 노드가 존재한다면
    if(hash->table[key] != NULL) {
        // 기존의 맨 앞 노드의 전 노드로 새 노드를 추가한다 (맨 앞에 추가한다)
        hash->table[key]->prevNode = newNode;
        newNode->nextNode = hash->table[key];
    }
    // 맨 첫 노드를 새 노드로 설정한다
    hash->table[key] = newNode;

}

ChainNode* ChainHashSearch(ChainHash* hash, int data) {
    // table의 index
    int key = Hasing(data); // 해당 data의 위치를 가져옴
    ChainNode* node = hash->table[key]; // 해시 테이블의 첫 번째 데이터 가져옴

    // 해당 위치에 연결되어 있는 모든 노드들을 탐색
    while(node != NULL) {
        if(node->data == data) {
            return node;
        }
        node = node->nextNode;
    }

    return NULL;
}

void ChainHashRemoveData(ChainHash* hash, int data) {
    int key = Hasing(data); // 삭제하려는 데이터의 index 값 가져옴
    // 해당 데이터를 가지는 노드를 탐색해서 가져온다
    ChainNode* node = ChainHashSearch(hash, data);
    // 만약 노드가 없었다면 == 해당 데이터는 원래 저장이 안되었던 것
    if(node == NULL) {
        puts("Error : Data Not Found. Not Exist.");
        return;
    }

    ChainNode* prevNode = node->prevNode;
    ChainNode* nextNode = node->nextNode;

    if(prevNode != NULL && nextNode == NULL) {
        // 앞은 있는데 뒤에는 없네 => 삭제할 노드가 마지막 노드임
        prevNode->nextNode = NULL;
    }
    else if(prevNode != NULL && nextNode != NULL) {
        // 앞 뒤에 노드가 존재함
        prevNode->nextNode = nextNode;
        nextNode->prevNode = prevNode;
    }
    else if(prevNode == NULL && nextNode != NULL) {
        // 앞에는 없는데 뒤에는 있네 => 삭제할 노드가 맨 처음
        nextNode->prevNode = NULL;
        hash->table[key] = nextNode; // 내 뒷 노드를 이제 맨 처음 노드라고 해준다
    }

    free(node);

}

void ChainHashPrint(ChainHash* hash) {
    for (int i = 0; i < hash->size; ++i) {
        printf("=== 현재 해시 KEY: [%d] === \n", i);

        // 첫번째 노드
        ChainNode * node = hash->table[i];
        if(node == NULL) {
            puts("- Empty -");
            continue;
        }
        // 첫번째 노드가 존재한다면
        while(node != NULL) {
            printf("%d ", node->data);
            node = node->nextNode;
        }
        puts("");
    }

}


void ChainHashMain() {
    ChainHash hash;
    ChainHashInitialize(&hash, 10);
    ChainHashAddData(&hash, 2);
    ChainHashAddData(&hash, 26);
    ChainHashAddData(&hash, 0);
    ChainHashAddData(&hash, 2);
    ChainHashAddData(&hash, 3);
    ChainHashAddData(&hash, 4);
    ChainHashAddData(&hash, 15);
    ChainHashAddData(&hash, 20);
    ChainHashAddData(&hash, 21);
    ChainHashAddData(&hash, 15);
    ChainHashAddData(&hash, 21);
    ChainHashAddData(&hash, 21);

    ChainHashRemoveData(&hash, 13); // 가장 마지막 데이터
    ChainHashRemoveData(&hash, 15); // 맨 앞 데이터 삭제
    ChainHashRemoveData(&hash, 5); // 없는 데이터 삭제
    ChainHashRemoveData(&hash, 20); // 하나만 있는 데이터 삭제


    ChainHashPrint(&hash);

}