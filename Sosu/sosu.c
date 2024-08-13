#include <stdio.h>
#include <math.h>

// 보통(brute_force)으로 소수탐색하기
// 1000이하의 소수를 나열 (ver1)
void normal_sosu_search() {
    printf("normal_sosu_search \n");
    unsigned int counter = 0;

    // 2 ~ 1000 까지의 숫자
    for (int i = 2; i < 1000; ++i) {
        int check = 1;
        // i가 소수인지 판단
        for (int j = 2; j < i; ++j) {
            counter++;
            if(i % j == 0) {
                check = 0; // 소수가 아니였음
                break;
            }
        }
        if(check) {
            printf("%d\n", i);
        }
    }
    printf("counter : %d", counter);
}

// 에라토스테네스의 체 (ver2) - 동적 계획법 Dynamic programming
// 소수를 찾았다면 이미 얻은 소수를 사용해서 판단
void eratosthenes_sosu() {
    printf("== eratosthenes_sosu == \n");
    int primes[500]; // 소수를 저장하는 배열
    int ptr = 0; // 이미 얻은 소수의 개수
    int counter = 0;
    primes[ptr++] = 2; // 2는 소수이다.
    // 짝수는 제외 홀수만 판단
    for (int n = 3; n < 1000; n+=2) {
        // 이미 얻은 소수로 나눔
        int check = 1;
        for (int i = 0; i < ptr; ++i) {
            counter++; // 소수 판단 시도시 counter + 1
            if(n % primes[i] == 0) {
                check = 0;
                break;
            }
        }
        // 마지막까지 break가 안되었다면 소수임
        if(check == 1) {
            // 소수를 저장하는 배열에 저장함
            primes[ptr++] = n;
        }

    }

    // 배열에 넣었던 모두 소수 출력
    for (int i = 0; i < ptr; ++i) {
        printf("%d\n", primes[i]);
    }

    // 카운터 출력
    printf("counter : %d \n", counter);

}

// 제곱근으로 소수 판단하기 (제일 쉽고 간단하며 빠름)
void sqrt_sosu() {
    unsigned long counter = 2;
    // 5 ~ 홀수만 판단하기
    for (int i = 5; i < 1000; i += 2) {
        int check = 1;
        int sqrtResult = sqrt(i); // i의 제곱근 계산
        // printf(" i : %d / sqrt : %d \n", i, sqrtResult);
        for (int j = 2; j <= sqrtResult; ++j) {
            counter++;
            if(i % j == 0) {
                check = 0;
                break; // 소수가 아님
            }
        }
        // 소수 찾음
        if(check == 1) {
            printf("%d \n", i);
        }
    }

    printf("counter : %lu\n", counter);
}

// 소수 탐색 메인
void sosu_main() {
    printf("==== sosu _main ==== \n");
    // normal_sosu_search();
    // eratosthenes_sosu();
    sqrt_sosu();
}
