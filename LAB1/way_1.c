#include <stdio.h>

int main(void) {
    double x, y = 0;
    int defined = 0;

    printf("Input x: ");
    scanf("%lf", &x);

    if (x > -10) {
        if (x <= -5) {
            y = x * x * x - 6;
            defined = 1;
        } else if (x > 5) {
            if (x <= 15) {
                y = x * x * x - 6;
                defined = 1;
            } else if (x >= 25) {
                y = 2 * x * x * x - 3 * x + 2;
                defined = 1;
            }
        }
    }

    if (defined == 1) {
        printf("Result: x = %.4f, y = %.4f\n", x, y);
    } else {
        printf("Result: function is undefined for x = %.4f\n", x);
    }

    return 0;
}
