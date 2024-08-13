#ifndef OPENADDRESS_H
#define OPENADDRESS_H

char* statusName[] = {"OCCUPIED", "EMPTY", "DELETED"};

// 채워져있음, 비어있음, 삭제됨 (3가지 상태 정의)
typedef enum {
    OCCUPIED, EMPTY, DELETED
} STATUS;

// 해시 테이블의 배열에 들어가는 버킷을 정의
typedef struct {
    int data; // 해당 버킷에 저장된 실제 데이터
    STATUS status; // 이 버킷의 현재 상태
} Bucket;

// 해시 테이블
typedef struct {
    int size; // 최대 크기
    Bucket** table; // 해시 테이블 그 자체
} OpenAddressHash;

#endif //OPENADDRESS_H
