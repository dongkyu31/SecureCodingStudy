/*
 * EXP-01. 연산자 우선순위를 나타내는데 괄호를 사용하라
 *
 * 괄호를 적절하게 사용하며 우선순위 때문에 발생하는 실수를 피할 수 있으며
 * 방어적으로 에러를 줄일 수 있고 코드 가독성도 높아진다.
 *
 */

#if 0
// 위험한 코드 1.
// 연산자 우선순위를 잘못 이해하여 코드가 의도대로 실행되지 않는다.
#include <stdio.h>

int is_even(int x) {
    return x & 1 == 0 ? 1 : 0;
}

int main() {
    int n = 2;

    if (is_even(n))
        printf("even\n");
    else
        printf("odd\n");

    return 0;
}
#endif

#if 0
// 해결 방법
// 표현식이 의도대로 평가되도록 괄호를 사용한다.
#include <stdio.h>

int is_even(int x) {
    return (x & 1) == 0 ? 1 : 0;
}

int main() {
    int n = 2;

    if (is_even(n))
        printf("even\n");
    else
        printf("odd\n");

    return 0;
}
#endif

#if 0
// 위험한 코드 2.
// 연산자 우선순위를 잘못 이해하여 코드가 의도대로 실행되지 않는다.
#include <stdio.h>

void incr(int* p) {
    *p++;
}

int main() {
    int cnt = 0;

    incr(&cnt);
    printf("cnt = %d\n", cnt);

    return 0;
}
#endif

#if 0
// 해결 방법
// 표현식이 의도대로 평가되도록 괄호를 사용한다.
#include <stdio.h>

void incr(int* p) {
    (*p)++;
}

int main() {
    int cnt = 0;

    incr(&cnt);
    printf("cnt = %d\n", cnt);

    return 0;
}

#endif
