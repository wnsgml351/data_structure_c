#ifndef CHAINHASH_H
#define CHAINHASH_H

// 링크드 리스트
typedef struct __node {
    int data; // 정수 데이터 (실제로 저장되는 데이터)
    struct __node *nextNode; // 다음 노드
    struct __node *prevNode; // 이전 노드
} ChainNode;

// 해시 테이블 자체
typedef struct {
    int size; // 해시 테이블의 크기 (최대)
    ChainNode **table; // 해시 테이블의 첫 번째 요소에 대한 포인터
} ChainHash;

// 해시 함수 정의(해싱 연산) (key 값의 해시 값을 반환)
int Hasing(int key);


#endif //CHAINHASH_H
