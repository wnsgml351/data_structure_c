#ifndef MEMBER_H
#define MEMBER_H

typedef struct {
    int no; // 학번
    char name[20]; // 이름
} Member;

// 멤버를 생성해서 생성된 멤버를 반환함
const Member* create_member();

// 멤버 한명을 전달받아서 해당 멤버의 내용을 출력함
void print_member(const Member* member);

#endif //MEMBER_H
