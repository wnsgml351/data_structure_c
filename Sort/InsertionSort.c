#include <stdio.h>
#include "Sort.h"
#include "InsertionSort.h"

void InsertionSort(int arr[]) {
    puts("===== insertion sort =====");
    int j;
    for (int i = 0; i < 9; ++i) {
        int insertData = arr[i];
        printf("insertData: [%d]\n", insertData);
        // 현재 삽입대상의 앞쪽부터 거꾸로 버블정렬 방식을 사용함
        for (j = i-1; j >=0; j--) {
            if(arr[j] > insertData) {
                arr[j + 1] = arr[j];
            } else {
                // 정렬 위치로 왔다 arr[j] <= insertData
                break;
            }
        }
        PrintArr(arr);
        arr[j + 1 ] = insertData;
    }

}
