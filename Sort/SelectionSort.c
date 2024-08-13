#include "SelectionSort.h"
#include <stdio.h>

// 배열에서 최솟값의 인덱스를 찾기
int FindMinValueIndex() {
    int arr[] = {5,9,3,1,2,8,4,7,6};

    int min = arr[0]; // 일단은 '제일 앞 수가 제일 작다!' 라고 판단
    int minIndex = 0; // 최솟값이 있는 위치
    for (int i = 1; i < 9; ++i) {
        // 만약 현재 숫자가 내가 알고 있던 최솟값보다 작다면
        if(arr[i] < min) {
            // 내가 알고 있는 최솟값을 현재 숫자로 변경한다
            min = arr[i];
            minIndex = i;
        }
    }
    // printf("min: [%d] AND index: [%d]\n", min, minIndex);
    return minIndex;
}

void SelectionSort() {
    for (int i = 0; i < 8; ++i) {
        int minIndex = FindMinValueIndex();
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

}