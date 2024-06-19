#include <stdio.h>
#define MAX_N 10000
int is_prime[MAX_N + 5]; // 初始值全为0表示全部是素数 
int main() {
    for (int i = 2; i * i <= MAX_N; i++) { // 当i的平方超过N就停止筛选
        if (!is_prime[i]) { // 如果i是素数就开始筛选
            for (int j = i * i; j <= MAX_N; j += i) { // j每次增加i，筛掉所有i的倍数
                is_prime[j] = 1; // 非素数标记为1 
            }
        }
    }
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) { // 找出所有值为0的数就是素数
            printf("%d ", i);  // 打印出这些素数
        }
    }
    printf("\n");
    return 0;
}
