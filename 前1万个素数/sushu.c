#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 函数声明
void generate_primes(int *primes, int n);

int main() {
    int n = 10000; // 需要生成的素数数量
    int *primes = (int *)malloc(n * sizeof(int));
    
    if (primes == NULL) {
        printf("内存分配失败。\n");
        return 1;
    }
    
    generate_primes(primes, n);
    
    // 输出生成的素数
    for (int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
    
    free(primes);
    return 0;
}

void generate_primes(int *primes, int n) {
    int count = 0; // 已生成的素数数量
    int number = 2; // 当前检查的数字
    while (count < n) {
        bool is_prime = true;
        
        // 检查当前数字是否为素数
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                is_prime = false;
                break;
            }
        }
        
        if (is_prime) {
            primes[count] = number;
            count++;
        }
        
        number++;
    }
}
