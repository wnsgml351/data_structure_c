#include "recursive.h"

#include <stdio.h>

// 단순 for 팩토리얼
void factorial() {
    int sum = 1;
    int number = 5;
    for (int i = 1; i <= number; ++i) {
        sum *= i;
    }
    printf("%d ! => %d", number, sum);
}



// 재귀를 사용한 팩토리얼
int recursive_factorial(int n) {
    if(n <= 1) {
        return 1;
    }
    return n * recursive_factorial(n -1);
}

// 재귀를 사용한 최대공약수 구하기 (유클리드 호제법)
// greatest common divisor
int recursive_gcd(int n1, int n2) {
    if(n2 == 0) { // n2가 0이라면 마지막에 나눴던 숫자인 n1이 정답
        return n1;
    }

    // 기존에 n2를 n1 자리로, 나머지 결과를 n2 자리로 이동
    return recursive_gcd(n2, n1 % n2);
}

// 재귀로 피보나치 수열 구하기
// n1: 전전 항
// n2: 전 항
// count: 현재까지 진행한 항의 개수(1, 1이 고정이라서 현재는 3항)
// n: 내가 목표로 하는 항의 개수(30항을 목표로)
int fibonacci(int n1, int n2, int count, int n) {
    if(count > n) { // 현재 항까지 왔으면 현재 항을 구해서 반환
        return n1 + n2; // 현재 항은 앞 두항을 더 해야한다.
    }
    // 전 항을 전전항으로 다음 전항을 계산 결과로
    return fibonacci(n2, n1+n2, count+1, n);
}

void dynamic_fibonacci() {
    int fibonacci[5];
    fibonacci[0] = 1;
    fibonacci[1] = 1;
    for (int i = 2; i < 5; ++i) {
        fibonacci[i] = fibonacci[i-2] + fibonacci[i-1];
    }
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", fibonacci[i]);
    }
    printf("피보나치의 5번째 항: %d\n", fibonacci[4]);
}

/*
 * 1. 작은 원반 n-1개를 (맨 아래 제외한 원반을) A => B 옮김
 * 2. 큰 원반 (맨 아래) 1개를 A => C로 옮김
 * 3. 작은 원반 (1단계의 원반들) n-1개를 B => C로 옮김
 */
// num개의 원반을 by를 거쳐서 from에서 to로 이동시키는 함수
void hanoi_tower_move(int num, char from, char by, char to) {
    if(num == 1) {
        printf("원반 1개를 %c에서 %c로 이동하였습니다.\n", from, to);
    } else {
        // 1) 실행 작은 원반 n-1개를 A => B로 이동
        hanoi_tower_move(num -1, from, to, by);
        // 2) 실행 큰 원반(맨 아래 제일 큰거 한개)를 A => C로 이동
        printf("원반 %d를 %c => %c로 이동하였습니다.\n", num, from, to);
        // 3) 실행 1)에서 옮김 원바을 B => C로 이동
        hanoi_tower_move(num-1,by,from,to);
    }
}

void hanoi_move2(int no, int x, int y) {
    if(no > 1) {
        hanoi_move2(no -1 , x, 6- x-y);
    }
    printf("원반 [%d]를(을) %d 기둥에서 %d 기둥으로 옮겼음\n", no, x,y);
    if(no > 1) {
        hanoi_move2(no-1, 6-x-y,y);
    }
}

void recursive_main() {
    // factorial();
    // printf("3! => %d\n", recursive_factorial(3));
    // int gcd = recursive_gcd(6, 12);
    // printf("1112와 685의 최대 공약수 : %d\n", gcd);
    // printf("1112와 685의 최소 공배수: %d\n", 6 * 12 / gcd);

    // 앞 두 항은 1로 고정, 현재는 3항부터 30항을 계산
    // int fiboResult = fibonacci(1,1,3,4);
    // printf("fiboResult : %d\n", fiboResult);

    // dynamic_fibonacci();
    // 막대 A의 원반 3개를
    // hanoi_tower_move(3, 'A', 'B', 'C');

    hanoi_move2(3, 1, 3);
}