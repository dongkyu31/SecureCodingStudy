#if 0
// ������ �ڵ� 1.
#include <stdio.h>

int main() {
    int input;

    if (scanf("%ld", &input) < 1) {
        perror("scanf");
        return -1;
    }

    printf("%d\n", input);
    return 0;
}
#endif 

#if 0
// �ذ� ���
#include <stdio.h>

int main() {
    int input;

    if (scanf("%d", &input) < 1) {
        perror("scanf");
        return -1;
    }

    printf("%d\n", input);
    return 0;
}
#endif 

#if 0
// ������ �ڵ� 2.
#include <stdio.h>

int main() {
    unsigned int a, b;
    unsigned long c;

    a = 1000000000;
    b = 10;
    c = (unsigned long)a * b;
    printf("c = %lu\n", c);

    return 0;
}
#endif 

#if 0
// �ذ� ���
#include <stdio.h>
#include <stdint.h> // uintmax_t

int main() {
    unsigned int a, b;
    uintmax_t c;

    a = 1000000000;
    b = 10;
    c = (uintmax_t)a * b;
    printf("c = %llu\n", c);

    return 0;
}
#endif 
