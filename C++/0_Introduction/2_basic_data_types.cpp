#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Input consists of the following space-separated values: int, long, char, float, and double, respectively.

    // Int ("%d"): 32 Bit integer
    // Long ("%ld"): 64 bit integer
    // Char ("%c"): Character type
    // Float ("%f"): 32 bit real value
    // Double ("%lf"): 64 bit real value

    int input1;
    long input2;
    char input3;
    float input4;
    double input5;

    scanf("%d %ld %c %f %lf", &input1, &input2, &input3, &input4, &input5);
    printf("%d\n%ld\n%c\n%.3f\n%.9lf\n", input1, input2, input3, input4, input5);

    return 0;
}
