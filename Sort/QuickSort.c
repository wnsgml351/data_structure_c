#include "QuickSort.h"

#include "Sort.h"

// 피벗의 인덱스를 return
int CreatePartition(int arr[], int left, int right) {
    // 현재 피봇은 부분배열에서 가장 왼쪽에 있는 요소를 선택했다
    int pivot = arr[left];
    int low = left + 1; // 부분 배열의 왼쪽 끝 요소 (피봇 제외)
    int high = right; // 부분 배열이 오른쪽 끝 요소

    while(low <= high) {
        // 피봇보다 큰 값이 나올때까지 low를 오른쪽으로 이동 시켜라
        while(pivot > arr[low]) {
            low++;
        }
        // 피봇보다 작은 값이 나올때까지 high를 오른쪽으로 이동 시켜라
        while(pivot < arr[high]) {
            high--;
        }

        // low(pivot보다 큰 수임)와 high 위치 값 (pivot보다 작은 값) 두 개를 교환
        if(low <= high) {
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }

    }

    // 위 while이 끝났을때는 low와 high가 양 옆에서 중앙으로 좁혀오다가 교차가 되었다는것
    // 교차되는 그 index의 왼쪽에는 pivot보다 작은 값만 모여있고, 오른쪽에는 pivot보다 큰 값만 모여있게 된다.
    // 피벗과 high의 위치를 교환 (high의 위치는 pivot보다 작은 값들 중 제일 오른쪽 값)
    int temp = arr[left];
    arr[left] = arr[high];
    arr[high] = temp;
    // 선택한 pivot은 정렬이 끝나게 된다. (다음 파티션의 기준이 되는값이 된다)
    return high;
}

// 피봇을 선택하고, 왼쪽과 오른쪽으로 그룹을 나눠서 정렬
void SelectPivotAndSort(int arr[], int left, int right) {
    // 왼쪽 index가 오른족 index보다 작다면
    if(left <= right) {
        // 파티션을 생성하고, 기준이 되는 피봇을 가져온다 (피봇이 결정된 위치)
        int pivot = CreatePartition(arr, left, right);
        PrintArr(arr);
        // 피봇의 왼쪽 그룹을 정렬한다
        SelectPivotAndSort(arr, left, pivot -1);
        // 피봇의 오른쪽 그룹을 정렬한다
        SelectPivotAndSort(arr, pivot + 1, right);
    }
}

void QuickSortMain(int arr[], int length) {
    SelectPivotAndSort(arr, 0, length -1);
}