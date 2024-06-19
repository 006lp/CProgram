#include <stdio.h>
#define MAXN 50
int josephus(int n, int m){
    if (n == 1)
        return 0;
    else
        return (josephus(n - 1, m) + m) % n;
}
int main(){
    int m, n = 47;
    for(m = 1; m <= n; m++) {
        if(josephus(n, m) == 0) {
            printf("当M为%d时，最后是你自己留下来。\n", m);
        }
    }
    return 0;
}
