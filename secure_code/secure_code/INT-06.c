/*
 *  INT-06. 숫자 값에는 명시적으로 signed 또는 unsigned 값을 사용하라
 *
 *  char, signed char, unsigned char 를 통틀어 문자 타입(character type)이라고 한다.
 *  숫자 값을 저장할 경우, signed char나 unsigned char를 사용해야 문자 타입의 부호와 상관없이
 *  호환 가능한 코드를 만드는 유일한 방법이다.
 */

#if 0
// 위험한 코드
// 문자 타입의 변수 c는 signed char 또는 unsigned char 타입일 수 있다.
// 부호의 유무에 따라 값은 달라질 수 있다.
#include <stdio.h>

int main() {
    char c = 200;
    int i = 1000;

    printf("%d / %d = %d\n", i, c, i / c);
    return 0;
}
#endif 

#if 0
// 해결 방법
// unsigned char로 선언하면 char의 부호와 상관없이 동작해 그 값을 예측할 수 있다.
#include <stdio.h>

int main() {
    unsigned char c = 200;
    int i = 1000;

    printf("%d / %d = %d\n", i, c, i / c);
    return 0;
}
#endif 
