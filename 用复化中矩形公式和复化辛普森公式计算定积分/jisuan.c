#include <stdio.h>
#include <math.h>

// 被积函数 f(x) = x * e^x
double f(double x) {
    return x * exp(x);
}

// 解析解，积分值为1
double true_integral() {
    return 1.0;
}

// 复化中矩形公式
double midpoint_rule(int N) {
    double a = 0.0, b = 1.0;
    double h = (b - a) / N;
    double sum = 0.0;
    for (int i = 0; i < N; ++i) {
        double x = a + (i + 0.5) * h;
        sum += f(x);
    }
    return h * sum;
}

// 复化辛普森公式
double simpson_rule(int N) {
    double a = 0.0, b = 1.0;
    double h = (b - a) / N;
    double sum = f(a) + f(b);

    for (int i = 1; i < N; i += 2) {
        sum += 4 * f(a + i * h);
    }
    for (int i = 2; i < N; i += 2) {
        sum += 2 * f(a + i * h);
    }
    return (h / 3) * sum;
}

int main() {
    int N_values[] = {16, 32, 64, 128, 256, 512, 1024};
    int num_values = sizeof(N_values) / sizeof(N_values[0]);
    double exact_value = true_integral();

    printf("N\t中矩形结果\t误差\t\t误差比\t\t辛普森结果\t误差\t\t误差比\n");
    double prev_midpoint_error = 0.0;
    double prev_simpson_error = 0.0;

    for (int i = 0; i < num_values; ++i) {
        int N = N_values[i];
        double midpoint_result = midpoint_rule(N);
        double simpson_result = simpson_rule(N);
        double midpoint_error = fabs(midpoint_result - exact_value);
        double simpson_error = fabs(simpson_result - exact_value);
        double midpoint_error_ratio = (i == 0) ? 0.0 : prev_midpoint_error / midpoint_error;
        double simpson_error_ratio = (i == 0) ? 0.0 : prev_simpson_error / simpson_error;
        prev_midpoint_error = midpoint_error;
        prev_simpson_error = simpson_error;

        printf("%d\t%.6f\t%.6e\t%.2f\t\t%.6f\t%.6e\t%.2f\n",
            N, midpoint_result, midpoint_error, midpoint_error_ratio,
            simpson_result, simpson_error, simpson_error_ratio);
    }
    
    return 0;
}
