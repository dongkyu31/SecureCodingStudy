/*
 * EXP-04. const를 캐스트로 없애지 마라
 *
 * const로 선언된 객체를 비 상수 객체로 변환하여 사용할 경우, 의도하지 않은 결과가 나타날 수 있다.
 *
 */

#if 0
// 위험한 코드
// strlen 함수 내부에서 인자로 전달된 문자열의 값을 변경할 수 있다.
#include <stdio.h>

int str_len(const char* s) {
    char* p = s;
    while (*p)
        ++p;
    return p - s;
}

int main() {
    char str[] = "hello";
    printf("%d\n", str_len(str));

    return 0;
}
#endif

#if 0
// 해결 방법
// 비 상수 객체의 포인터로 캐스틍하지 않는다.
#include <stdio.h>

int str_len(const char* s) {
    const char* p = s;
    while (*p)
        ++p;
    return p - s;
}

int main() {
    char str[] = "hello";
    printf("%d\n", str_len(str));

    return 0;
}
#endif
