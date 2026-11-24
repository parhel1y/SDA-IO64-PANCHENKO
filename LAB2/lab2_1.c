#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("n must be >= 1\n");
        return 1;
    }

    long long count = 0;
    double x = 1.0 / 3.0;
    count += 2;
    double minus_x = -x;
    count += 2;
    double sum = 0.0;
    count += 1;

    count += 1;
    for (int i = 0; i <= n; i++) {
        count += 1;
        double a = 1.0;
        count += 1;

        count += 1;
        for (int j = 1; j <= i; j++) {
            count += 1;
            a *= minus_x;
            count += 2;
            count += 2;
        }
        count += 1;

        sum += a;
        count += 2;
        count += 2;
    }
    count += 1;

    printf("S = %.7f\n", sum);
    printf("Operations: %lld\n", count);

    return 0;
}
