#include <stdio.h>
#include <math.h>

// 定义函数 f(x) 和它的导数 f'(x)
double f(double x) {
    // 这里以 f(x) = x^2 - 2 为例
    return x * x - 2;
}

double df(double x) {
    // f'(x) = 2x
    return 2 * x;
}

// 牛顿迭代法函数
double newton_raphson(double initial_guess, double tol, int max_iter) {
    double x = initial_guess;
    int iter = 0;

    while (iter < max_iter) {
        double fx = f(x);
        double dfx = df(x);

        if (fabs(dfx) < tol) {
            // 导数太小，停止迭代
            printf("导数太小，停止迭代。\n");
            break;
        }

        double x_next = x - fx / dfx;

        if (fabs(x_next - x) < tol) {
            // 收敛到所需精度
            printf("在 %d 次迭代后收敛到 %lf。\n", iter, x_next);
            return x_next;
        }

        x = x_next;
        iter++;
    }

    printf("在 %d 次迭代内未收敛。\n", max_iter);
    return x;
}

int main() {
    double initial_guess = 1.0; // 初始猜测值
    double tol = 1e-6;          // 收敛精度
    int max_iter = 1000;        // 最大迭代次数

    double root = newton_raphson(initial_guess, tol, max_iter);
    printf("估计的根: %lf\n", root);

    return 0;
}
