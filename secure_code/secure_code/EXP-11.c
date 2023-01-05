/* 
 * EXP-11. 함수의 반환 값을 인접한 다음 시퀀스 포인터에서
 * 접근하거나 수정하지 마라.
 *
 * C99에서는 다음과 같이 언급하고 있다
 *
 * 함수 호출 결과 값을 다음 시퀀스 포인트에서 수정하려고 한다면,
 * 정의되지 않은 결과를 얻게 한다. 
 *
 * C 함수는 배열을 반환할 수 없으나 배열을 가진 구조체가 공용체는 반환할 수 있다.
 * 만약, 함수 호출 후 얻은 반환 값에 배열이 있다면 그 배열은 표현식 내에서
 * 접근되거나 수정되면 안된다.
 */

#if 0
// 위험한 코드
// 다음의 코드는 함수 호출 후 얻은 구조체로부터 배열을 얻어오려 하고 있다. 
// 함수 반환 값의 수명은 다음 시퀀스 포인트 전에 끝나게 되므로 함수에 의해 반환된 구조체는
// 더 이상 유효하지 않거나 다른 값으로 변경될 가능성이 크다. 

#include <stdio.h>
#include <string.h>

typedef struct {
    char buf[32];
} String;

String make_str(const char* s) {
    String str;
    strcpy(str.buf, s);
    return str;
}

int main() {
    printf("%s\n", make_str("hello").buf);
    return 0;
}
#endif 

#if 0
// 해결 방법
// 반환되는 구조체를 저장 후 사용한다.
#include <stdio.h>
#include <string.h>

typedef struct {
    char buf[32];
} String;

String make_str(const char* s) {
    String str;
    strcpy(str.buf, s);
    return str;
}

int main() {
    String str = make_str("hello");
    printf("%s\n", str.buf);

    return 0;
}
#endif 

