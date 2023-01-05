/*
 * EXP-03. 구조체의 크기가 구조체 멤버들 크기의 함이라고 가정하지 마라
 *
 *  구조체의 크기는 항상 멤버들 크기의 총합과 일치하지 않는다. C99 표준에 의하면
 *  "구조체 객체에는 명명되지 않는 패딩(padding)이 들어갈 수 있으며, 앞쪽에는 위치
 *  하지 않는다"고 명시되어 있다. 이는 CPU가 메모리에 빠르게 접근할 수 있도록 하기
 *  위함이다. 구조체의 패딩이 어떻게 포함될지는 컴파일러의 정의에 따른다.
 *
 *
 *
 */

#if 0
// 위험한 코드
// 다음은 구조체의 크기가 멤버들의 총합과 같다고 가정하고 있다.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _string {
    char arr[10];
    int len;
} string;

string* make_str(const char* str) {
    string* p = malloc(14);
    strcpy(p->arr, str);
    p->len = strlen(str);

    return p;
}

int main() {
    string* hello = make_str("hello");

    string buf;
    memcpy(&buf, hello, sizeof(string));

    free(hello);
    return 0;
}
#endif

#if 0
// 해결 방법
// sizeof 연산자를 이용한다.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _string {
    char arr[10];
    int len;
} string;

string* make_str(const char* str) {
    string* p = malloc(sizeof(string));
    strcpy(p->arr, str);
    p->len = strlen(str);

    return p;
}

int main() {
    string* hello = make_str("hello");

    string buf;
    memcpy(&buf, hello, sizeof(string));

    free(hello);
    return 0;
}
#endif
