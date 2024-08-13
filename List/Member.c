#include "Member.h"

#include <stdio.h>
#include <stdlib.h>

// 멤버를 생성해서 생성된 멤버를 반환함
const Member* create_member() {
    puts("=== 새 멤버 생성 ===");
    Member* member = (Member*)calloc(1, sizeof(Member));
    printf("유저학번 입력 >> ");
    scanf("%d", &member->no);
    printf("유저이름 입력 >> ");
    scanf("%s", member->name);
    return member;
}

// 멤버 한명을 전달받아서 해당 멤버의 내용을 출력함
void print_member(const Member* member) {
    printf("학번 %d / 이름: %s\n", member->no, member->name);
}
