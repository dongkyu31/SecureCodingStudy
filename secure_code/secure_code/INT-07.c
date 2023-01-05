/*
 * INT-07. 열거혐 상수가 유일한 값으로 매핑되도록 보장하라
 *
 * C 언어의 열거형의 열거자는 정수형으로 매핑된다. 일반적으로 열거형의 
 * 각 열거자가 개별 값으로 대응된다고 생각하지만 서로 같은 값을 갖는 
 * 명확하지 않은 에러가 종종 만들어지기도 한다.
 *
 */
#if 0
// 위험한 코드
// 열거자의 값이 중복되면 모호성으로 인해 에러가 발생할 가능성이 높다.
#include <stdio.h>

enum { DEBUG, WARN, ERROR = 0 };

int main() {
    printf("DEBUG = %d\n", DEBUG);
    printf(" WARN = %d\n", WARN);
    printf("  ERR = %d\n", ERROR);

    if (DEBUG == ERROR)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
#endif 

#if 0
// 해결 방법
// 열거형 선언 시, 아래의 방법을 따르도록 하는 것이 좋다
// 명시적 선언을 하지 않는다.
// 첫 번째 열거자에 대해서만 값을 지정한다.
// 모든 열거자에 대하여 명시적으로 값을 지정한다.

#include <stdio.h>

enum { DEBUG, WARN, ERROR };

int main() {
    printf("DEBUG = %d\n", DEBUG);
    printf(" WARN = %d\n", WARN);
    printf("  ERR = %d\n", ERROR);

    if (DEBUG == ERROR)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
#endif 


