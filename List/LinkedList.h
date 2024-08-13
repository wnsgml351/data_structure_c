#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Member.h"

// 노드는 다음 노드가 누구인지 알고 있는 형태임
typedef struct __node {
    Member data; // Node가 가지는 실제 데이터
    struct __node* next; // 다음 노드의 주소 (다음 노드를 가리킴)
    struct __node* prev; // 이전 노드의 주소 (이전 노드를 가리킴)
} Node;

typedef struct {
    Node* head; // 가장 앞(헤드) 노드 => 처음 만들어진 친구
    Node* tail; // 가장 마지막(꼬리) 노드
} List;

// 연결 리스트를 하나 생성함 (초기화)
void initialize(List *list);
// 가장 마지막에 노드를 삽입함 (꼬리부분) - 해당 멤버 내용으로
void append(List* list, const Member* member);
// 노드를 삽입
void insert(List* list, int index, const Member* member);
// 현재 연결리스트에 있는 모든 노드를 순서대로 출력하기
void print_list(const List* list);

void linkedList_main();

#endif //LINKEDLIST_H
