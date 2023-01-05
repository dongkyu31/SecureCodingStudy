/*
 * EXP-08. 어썰션의 부수 효과를 피하라
 *
 * assert 와 함께 사용되는 표현식은 부수 효과를 가지면 안된다. 
 * 이는 assert 함수가 매크로이기 때문이고 매크로 함수 내에서
 * 값의 할당, 증가, 감소, 메모리 변수의 접근, 함수 호출 등은
 * 미정의 동작이다.
 */

#if 0
// 위험한 코드
// assert 함수에서 값을 증가시키고 있다. 
#include <stdio.h>
#include <assert.h>

int process(int i) {
    assert(i++ > 0);
    printf("%d\n", i);
}

int main() {
    int num;

    printf("input size: ");
    int ret = scanf("%d", &num);
    if (ret != 1)
        printf("scanf error\n");
    else
        process(num);

    return 0;
}
#endif

#if 0
// 해결 방법
// assert 함수에서 증가 연산자를 제거한다.
#include <stdio.h>
#include <assert.h>

int process(int i) {
    assert(i > 0);
    ++i;
    printf("%d\n", i);
}

int main() {
    int num;

    printf("input size: ");
    int ret = scanf("%d", &num);
    if (ret != 1)
        printf("scanf error\n");
    else
        process(num);

    return 0;
}

#endif
