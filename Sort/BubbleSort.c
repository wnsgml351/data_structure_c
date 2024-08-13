#include "BubbleSort.h"
#include "Sort.h"
#include <stdio.h>
#include <stdbool.h>

void PrintArr() {
    for (int i = 0; i < 9; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void BubbleSort() {


    // arr의 개수 -1 만큼 round를 진행
    for (int i = 0; i < 8; ++i) {
        // endCheck가 true라면 정렬이 끝났다고 판단
        int endCheck = true;
        // 처음부터 끝까지 이동하면서 두 수의 교환 작업을 하는 1 round
        for (int i = 0; i < 8; ++i) {
            int num1 = arr[i];
            int num2 = arr[i+1];
            // 앞 수가 뒷 수보다 크다 == 서로 교환!
            // 한번이라도 교환되었다면 아직 정렬중이다!
            if(num1 > num2) {
                int temp = num1;
                num1 = num2;
                num2 = temp;
                endCheck = false;
                PrintArr();
            }
            arr[i] = num1;
            arr[i+1] = num2;
        }

        if(endCheck) {
            break; // 정렬 끝
        }
    }

}

void BubbleSortMain() {
    BubbleSort();
    PrintArr();
}