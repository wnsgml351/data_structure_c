#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_null.h>

// 연결 리스트를 하나 생성함 (초기화)
void initialize(List *list) {
    list->head = NULL;
    list->tail = NULL;
}

// Node 객체를 하나 생성함
Node* create_node() {
    return (Node*)calloc(1, sizeof(Node));
}

// 생성한(생성된) 노드의 데이터를 설정 혹은 변경(수정)
// crntNode: 생성한(생성된) 노드
// member: 생성한 노드에 설정할 멤버 데이터
// nextNode: 생성한 노드의 다음 노드
void set_node_data(Node *crntNode, const Member* member, Node* nextNode) {
    crntNode->data = *member;
    crntNode->next = nextNode;
}

// 노드를 추가
void append(List* list, const Member* member) {

    // 노드를 하나 생성한다.
    Node* newNode = create_node();

    // 생성된 노드에 전달받은 멤버를 설정한다.
    set_node_data(newNode, member, NULL);

    // 리스트에 노드가 존재하지 않는다(헤드도 없다)
    if(list->head == NULL) {
        // 노드가 하나밖에 없어서 머리이자 꼬리이다
        list->head = newNode;
        list->tail = newNode;
        return;
    }

    // 마지막 노드의 다음 노드에 새 노드를 설정
    newNode->prev = list->tail;
    list->tail->next = newNode;
    list->tail = newNode;

}

// 노드를 삽입
void insert(List* list, int index, const Member* member) {
    Node* node = list->head;
    Node* findedNode = node; // 원래 index 위치에 있던 노드
    for (int i = 0; i < index; ++i) {
        if(node->next != NULL) {
            findedNode = node; // 현재 노드 저장
            node = node->next; // 다음 노드로 이동
        } else {
            // 다음 노드로 못갔으면 index만큼 못갔네...
            // 현재 존재하는 list 연결 리스트 개수보다 더 큰 숫자로 insert 하려는 것
            // 그럼 마지막에 넣어야 겠다.
            append(list, member);
            return;
        }
    }

    Node* newNode = create_node();
    newNode->data = *member;

    if(node != list->head) {
        node->prev->next = newNode;
    } else {
        list->head = newNode;
    }

    newNode->next = node;
    node->prev = newNode;

}

void remove_head_node(List* list) {
    // 머리가 꼬리인 노드가 하나인 상태면 그냥 없애면 끝
    if(list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
        free(list->head);
        return;
    }
    if(list->head != NULL) {
        Node* headNode = list->head;

        // 헤드의 다음 노드가 존재하면 다음 노드가 차기 헤드 노드가 되어야 함
        if(headNode->next != NULL) {
            list->head = headNode->next;
        }

        // 메모리에서 헤드 노드를 해제한다
        free(headNode);
    }
}

// 꼬리 노드를 삭제
void remove_tail_node(List* list) {

    // 머리가 꼬리인 노드가 하나인 상태면 그냥 없애면 끝
    if(list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
        free(list->head);
        return;
    }

    if(list->tail != NULL) {
        Node* tailNode = list->tail;
        list->tail = tailNode->prev;
        list->tail->next = NULL;

        free(tailNode);
    }
}

// 현재 연결리스트에 있는 모든 노드를 순서대로 출력하기
void print_list(const List* list) {
    puts(" === 모든 데이터 순회 === ");
    if(list->head == NULL) {
        puts("리스트가 비었습니다.");
        return;
    }

    // 맨 처음 노드
    Node* crntNode = list->head;

    // 다음 노드가 없을때까지 반복하며 노드가 가진 데이터인 멤버를 가져온다.
    while(crntNode != NULL) {
        // member 데이터를 출력하면 되므로 미리 만들어둔 print_member를 호출
        // print_member는 포인터 형태를 인자로 받으므로 & 를 붙여야 한다.
        print_member(&crntNode->data);
        crntNode = crntNode->next;
    }
}

void select_menu(List* list) {
    puts(" ======= 링크드리스트 기반 멤버 관리 ======");
    while(1) {
        int menu;
        puts("1) 멤버 추가 / 2) 멤버 삽입 / 3) 머리 제거 / 4) 꼬리 제거 / 10) 모든 멤버 출력하기");
        printf("메뉴를 선택하세요 >>> ");
        scanf("%d", &menu);
        switch (menu) {
            case 1: // 추가하기
                printf("노드(멤버)를 하나 추가합니다.\n");
                // 멤버를 하나 생성한 다음 리스트에 넘기면 리스트의 꼬리에 해당 멤버가 설정된 노드가 추가됨
                append(list, create_member());
                break;
            case 2: // 삽입하기
                printf("노드(멤버)를 하나 삽입합니다.\n");
                printf("몇 번째 index로 삽입할까요? >>> ");
                int index = 0;
                scanf("%d", &index);
                // 멤버를 하나 생성한 다음 리스트에 넘기면 리스트의 꼬리에 해당 멤버가 설정된 노드가 추가됨
                insert(list, index, create_member());
                break;
            case 3:
                remove_head_node(list);
                break;
            case 4:
                remove_tail_node(list);
                break;
            case 10: // 보기
                // 현재 가지고 있는 리스트 내부 출력
                print_list(list);
                break;
            case 99: //종료
                return;
        }
    }
    printf("노드(멤버)를 하나 추가합니다.\n");
    // 멤버를 하나 생성한 다음 리스트에 넘기면 리스트의 꼬리에 해당 멤버가 설정된 노드가 추가됨
    append(list, create_member());
    // 현재 가지고 있는 리스트 내부 출력
    print_list(list);
}

void linkedList_main() {
    List list; // 리스트 생성
    initialize(&list); // 리스트를 전달해서 초기화하기
    select_menu(&list); // 메뉴 선택하기
}
