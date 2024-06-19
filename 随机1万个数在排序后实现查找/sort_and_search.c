#include <stdio.h>
#include <stdlib.h>

// 数组长度定义
#define ARRAY_SIZE 10000

// 比较函数，用于qsort和bsearch
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int arr[ARRAY_SIZE];
    int i, target, *item;
    
    // 给数组元素赋初值（不调用 srand，所以使用默认种子）
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand();
    }
    
    // 排序数组
    qsort(arr, ARRAY_SIZE, sizeof(int), compare);
    
    // 打印排序后的数组（可选）
    // for (i = 0; i < ARRAY_SIZE; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
    
    // 输入要查找的目标值
    printf("请输入要查找的整数值: ");
    scanf("%d", &target);
    
    // 查找目标值
    item = (int*) bsearch(&target, arr, ARRAY_SIZE, sizeof(int), compare);
    
    // 打印查找结果
    if (item != NULL) {
        printf("找到 %d 在索引 %ld\n", target, item - arr);
    } else {
        printf("未找到 %d\n", target);
    }

    return 0;
}
