#include "OpenAddress.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "ChainHash.h"

// 재해싱 함수
int ReHashing(int key) {
    return (key + 1) % 13;
}

// 해시 테이블 초기화
void OpenAddressHashInitialize(OpenAddressHash* hash, int size) {
    // 만들고 싶은 size 크기만큼 Bucket을 저장할 수 있는 테이블 생성
    hash->table = calloc(size,sizeof(Bucket));
    hash->size = size;
    // 처음에 모든 버킷은 비어 있음
    for (int i = 0; i < size; ++i) {
        // 데이터가 없는 빈 버킷을 생성한다
        hash->table[i] = (Bucket*)calloc(1, sizeof(Bucket));
        // 이 버킷은 비었다 표시
        hash->table[i]->status = EMPTY;
    }
}

// 해시 테이블에 있는 데이터를 검색 (찾은 데이터를 가지는 버킷을 반환
Bucket* OpenAddressHashSearch(OpenAddressHash* hash, int data) {
    int key = Hasing(data);
    // 해당 key에 해당하는 위치의 bucket 가져오기
    Bucket* bucket = hash->table[key];
    // 재 hasing 횟수는 size 보다 작게 현재 버킷이 비어있지 않으면 재탐색
    for (int i = 0; i < hash->size && bucket->status != EMPTY; ++i) {
        // 데이터가 존재하고 내가 찾고 싶은 데이터랑 일치한다면
        if(bucket->status == OCCUPIED && bucket->data == data) {
            return bucket; // 찾은 버킷을 반환
        }
        key = ReHashing(key); // 재 해시
        bucket = hash->table[key]; // 재 해시한 위치의 버킷을 가져오기
    }
    // 아무리 찾았는데도 해당 데이터가 없었다 or 애초에 그 위치가 비어있다
    return NULL;
}

// 해시 테이블에 데이터를 추가하기
bool OpenAddressHashAddData(OpenAddressHash* hash, int data) {
    // 해당 데이터가 이미 존재한다면
    Bucket* searchBucket = OpenAddressHashSearch(hash, data);
    if(searchBucket != NULL) {
        printf("Error: [%d] 데이터는 이미 존재합니다!\n", data);
        return false;
    }

    // 데이터를 해시해서 key를 도출한다 (hash table의 index 도출)
    int key = Hasing(data);
    // 해당 위치의 버킷을 가져온다
    Bucket* bucket = hash->table[key];

    // 테이블 크기만큼 자리 찾기 시도한다
    for (int i = 0; i < hash->size; ++i) {
        // 버킷에 데이터가 없거나(비었거나), (지워졌거나) 그냥 데이터를 넣으면 된다
        if(bucket->status == EMPTY || bucket->status == DELETED) {
            bucket->data = data; // 버킷의 데이터를 설정한다
            bucket->status = OCCUPIED; // 버킷에 데이터가 있다고 설정한다
            hash->table[key] = bucket;
            return true; // 추가 성공
        }
        // 만약 그자리에 데이터가 있다면 재해시 해서 새로 자리 찾아감
        printf("[%d] key index is Exists => [%d]\n", key, hash->table[key]->data);
        key = ReHashing(key);
        bucket = hash->table[key];
    }

    // 재 해시를 테이블 크기만큼 시도했는데 자기 자리를 찾지 못했다면 실패
    return false; // 추가 실패
}

// 해시 테이블에 있는 데이터를 제거하기
void OpenAddressHashRemoveData(OpenAddressHash* hash, int data) {
    // 해당 데이터가 이미 존재한다면
    Bucket* searchBucket = OpenAddressHashSearch(hash, data);
    if(searchBucket == NULL) {
        printf("Error: [%d] 데이터가 존재하지않습니다!\n", data);
        return;
    }
    // 데이터를 찾았다면 삭제됨이라고 표시한다
    searchBucket->status = DELETED;
}

void OpenAddressHashPrint(OpenAddressHash* hash) {
    puts("===== OpenAddress Hashtable =====");
    for (int i = 0; i < hash->size; ++i) {
        printf("data: [%d] / status: [%s]\n", hash->table[i]->data, statusName[hash->table[i]->status]);
    }
}

void OpenAddressHashMain() {
    OpenAddressHash hash;
    OpenAddressHashInitialize(&hash, 12);

    puts("Add 14..");
    OpenAddressHashAddData(&hash, 14); // 14 % 13 == 1
    puts("Add 29..");
    OpenAddressHashAddData(&hash, 29); // 29 % 13 == 3
    puts("Add 5..");
    OpenAddressHashAddData(&hash, 5); // 5 % 13 == 5
    puts("Add 6..");
    OpenAddressHashAddData(&hash, 6); // 6 % 13 == 6
    puts("Add 34..");
    OpenAddressHashAddData(&hash, 34); // 34 % 13 == 8
    puts("Add 18..");
    OpenAddressHashAddData(&hash, 18); // 18 % 13 == 5 !충돌
    puts("Add 18..");
    OpenAddressHashAddData(&hash, 18); // 18 % 13 == 5 !충돌

    puts("==============");
    puts("Remove 14..");
    OpenAddressHashRemoveData(&hash, 14);

    puts("==============");
    puts("Remove 14..");
    OpenAddressHashRemoveData(&hash, 14);

    OpenAddressHashPrint(&hash);

}