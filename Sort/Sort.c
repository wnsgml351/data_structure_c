#include "Sort.h"
#include <stdio.h>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

void PrintArr(int arr[]) {
    for (int i = 0; i < 9; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void SortMain() {
    int arr[] = {5, 9, 3, 1, 2, 8,4,7,6};
    // BubbleSort(arr);
    // PrintArr(arr);
    // SelectionSort(arr);
    // InsertionSort(arr);
    // MergeSort(arr,  9);
    QuickSortMain(arr, 9);
    PrintArr(arr);

}