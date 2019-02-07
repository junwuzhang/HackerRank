#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int numA = *a;
    int numB = *b;

    *a = numA + numB;
    if (numA > numB){
        *b = numA - numB;
    } else{
        *b = numB - numA;
    }

}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
