#include "MergeSort.h"

#include <stdio.h>
#include <stdlib.h>

// 나눠진 두 그룹을 하나로 합친다
void MergeArr(int arr[], int left, int mid, int right) {
    int fIndex = left;
    int sIndex = left;
    int rIndex = mid + 1;

    // 병합되어 정렬된 결과 배열이 될 배열을 생성한다
    int* sortArr = (int*)calloc(right + 1, sizeof(int));
    // 왼쪽그룹과 오른쪽 그룹의 데이터를 전부 sortArr에 넣을때까지 반복
    while(fIndex <= mid && rIndex <= right) {
        // 왼쪽 그룹의 비교 대상 데이터가 오른쪽 그룹의 데이터보다 작다면
        if(arr[fIndex] <= arr[rIndex]) {
            // 왼쪽 그룹의 제일 왼쪽 데이터를 결과 배열에 저장
            sortArr[sIndex] = arr[fIndex];
            fIndex++;
        } else {
            // 오른쪽 그룹의 데이터가 더큼
            // 오른쪽 그룹의 제일 왼쪽 데이터를 결과 배열에 저장
            sortArr[sIndex] = arr[rIndex];
            rIndex++;
        }
        sIndex++;
    }

    // 왼쪽 혹은 오른쪽 그룹의 뎅이터를 전부 넣었음
    // 하지만, 전부 넣은 그룹 말고 다른 그룹은 데이터가 남아있을 수 있음
    // 오른쪽 그룹이 남았다 왼쪽 그룹은 전부 넣었다
    if(fIndex > mid) {
        // 오른쪽 그룹의 남은 값들을 전부 sortArr에 추가한다
        for (int i = rIndex; i <= right; i++) {
            sortArr[sIndex] = arr[i];
            sIndex++;
        }
    } else {
        // 왼쪽 그룹의 남은 값들을 전부 sortArr에 추가한다
        for (int i = fIndex; i <= mid; i++) {
            sortArr[rIndex] = arr[i];
            rIndex++;
        }
    }

    // 정렬했던 데이터들을 기존 배열에서 잘라온 그 부분에 순서대로 넣어야함
    for (int i = left; i <= right; i++) {
        arr[i] = sortArr[i];
    }

    // 정렬된 배열은 더이상 필요하지 않다. 메모리 해제
    free(sortArr);

}

// 배열을 반씩 나눈다
void DivideArr(int arr[], int left, int right) {
    int mid; // 중간지점
    if(left < right) {
        mid = (int)((left + right) / 2); // 중간 index
        printf("left: %d / right: %d / mid: %d \n",left,right,mid);
        DivideArr(arr, left, mid); // 왼쪽부터 중간까지 나눔
        DivideArr(arr, mid + 1, right); // 중간부터 오른쪽 끝까지 나눔
        MergeArr(arr,left,mid,right); // 나눠진 두 그룹을 합친다
    }
}

void MergeSort(int arr[], int length) {
    DivideArr(arr, 0, length -1);
}