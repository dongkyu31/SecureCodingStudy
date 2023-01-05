/*
 * DCL-11. 함수 정의와 맞지 않는 타입으로 함수를 변환하지 마라.
 *
 * 원래의 타입과 다른 타입의 함수를 참조하도록 함수 포인터를 사용하면 정의되지 않은
 * 결과를 초래한다. 때문에 함수 포인터를 사용할 경우, 정확한 타입을 선언해서 사용해야 
 * 한다. C99에서는 다음과 같이 언급하고 있다.
 *
 * 특정 타입에 대한 함수의 포인터는 다른 타입의 함수 포인터로 변환될 수 있고 결과는
 * 원래의 포인터와 같아진다. 호환되지 않는 타입의 함수를 호출하는데 함수 포인터가
 * 사용되면 알 수 없는 행동을 초래한다.
 *
 */
#if 0
// 위험한 코드
// 함수 포인터와 함수의 타입이 일치하지 않아 정의되지 않은 결과를 초래한다.
#include <stdio.h>
#include <signal.h>

int square(int a) { return a * a; }
int cube(int a) { return a * a * a; }
int add(int a, int b) { return a + b; }

int main() {
    int(*fp)(int);
    // ...

    fp = add;
    printf("%d\n", fp(1));

    return 0;
}
#endif

#if 0
// 해결 방법
// 정확한 타입의 포인터 변수를 선언한다.
#include <stdio.h>
#include <signal.h>

int square(int a) { return a * a; }
int cube(int a) { return a * a * a; }
int add(int a, int b) { return a + b; }

int main() {
    int(*fp)(int);
    // ...

    fp = add;
    printf("%d\n", fp(1,1));

    return 0;
}
#endif

