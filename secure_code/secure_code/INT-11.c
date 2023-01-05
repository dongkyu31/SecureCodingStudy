/*
 * INT-11. signed 정수의 연산이 오버플로되지 않도록 보장하라.
 *
 * C 언어에서 정수 오버플로는 정의되지 않는 동작이다. 구현에 따라서는 
 * 오버플로를 감지할 수 있지만 그렇지 않은 경우도 있으므로 오버플로가 
 * 발생되지 않도록 하는 것이 중요하다. 특히 신뢰할 수 없는 소스로 부터
 * 얻어진 부호 있는 정수 값에 대한 연산이 다음과 같이 사용될 때 더욱 그렇다.
 *
 * 	- 배열의 인덱스
 * 	- 포인터 연산
 * 	- 객체의 길이나 크기
 * 	- 배열의 경계
 * 	- 메모리 할당 함수의 인자
 * 	- 보안에 민감한 코드
 *
 */
#if 0
// 위험한 코드 1.
// 부호 있는 정수의 덧셈 도는 뺄셈 연산은 정수 오버플로가 일어날 수 있기 때문에
// 다음의 코드는 의도하지 않는 결과를 초래할 수 있다.

#include <stdio.h>
#include <limits.h>

int main() {
    signed int sint1, sint2, result = 0;
    sint1 = INT_MAX;
    sint2 = 1;

    result = sint1 + sint2;
    printf("result = %d\n", result);

    return 0;
}
#endif

#if 0
// 해결 방법
// 오버플로가 발생하기 전에 미리 테스트 한다.
#include <stdio.h>
#include <limits.h>

int main() {
    signed int sint1, sint2, result = 0;
    sint1 = INT_MAX;
    sint2 = 1;

    if (((sint1 > 0) && (sint2 > 0) && (sint1 > (INT_MAX - sint2))) ||
        ((sint1 < 0) && (sint2 < 0) && (sint1 < (INT_MIN - sint2)))) {
        fprintf(stderr, "int overflow!\n");
        exit(-1);
    }

    result = sint1 + sint2;
    printf("result = %d\n", result);

    return 0;
}

#endif

#if 1
// 위험한 코드 2.
// 부호 있는 정수의 곱셈 연산은 정수 오버플로가 일어날 수 있기 때문에 다음의 
// 코드는 의도하지 않는 결과를 초래할 수 있다.
#include <stdio.h>
#include <limits.h>

int main() {
    signed int sint1, sint2, result = 0;
    sint1 = INT_MAX;
    sint2 = 2;

	printf("sint1 is (%d)\n", sint1);
	printf("sint2 is (%d)\n", sint2);

    result = sint1 * sint2;
    printf("result = %d\n", result);

    return 0;
}
#endif

#if 0
// 해결 방법
// 오버플로가 발생하기 전에 미리 테스트 한다.
#include <stdio.h>
#include <limits.h>

int main() {
    signed int sint1, sint2, result = 0;
    sint1 = INT_MAX;
    sint2 = 2;

    if (sint1 > 0) {
        if (sint2 > 0) {    // 양수 * 양수
            if (sint1 > (INT_MAX / sint2)) {
                fprintf(stderr, "int overflow!\n");
                exit(-1);
            }
        }
        else {  // 양수 * 음수
            if (sint2 < (INT_MIN / sint1)) {
                fprintf(stderr, "int overflow!\n");
                exit(-1);

            }
        }
    }
    else {
        if (sint2 > 0) {    // 음수 * 양수
            if (sint1 < (INT_MIN / sint2)) {
                fprintf(stderr, "int overflow!\n");
                exit(-1);

            }
        }
        else {  // 음수 * 음수
            if ((sint1 != 0) && (sint2 < (INT_MAX / sint1))) {
                fprintf(stderr, "int overflow!\n");
                exit(-1);

            }
        }
    }

    result = sint1 * sint2;
    printf("result = %d\n", result);

    return 0;
}
#endif

#if 0
// 위험한 코드 3.
// 부호 있는 정수의 나눗셈 연산은 피제수가 최소값(INT_MIN)이고 제수가 -2인 경우,
// 2의 보수 표기에서 정수 오버플로가 일어날 수 있다. 때문에 다음의 코드는 
// 의도하지 않는 결과를 초래할 수 있다.
#include <stdio.h>
#include <limits.h>

int main() {
    signed int sint1, sint2, result = 0;
    sint1 = INT_MIN;
    sint2 = -1;

    result = sint1 / sint2;
    printf("result = %d\n", result);

    return 0;
}

#endif

#if 0
// 해결 방법
// 오버플로가 발생하기 전에 미리 테스트한다.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    signed int sint1, sint2, result = 0;
    sint1 = INT_MIN;
    sint2 = -1;

    if ((sint2 == 0) || ((sint1 == INT_MIN) && (sint2 == -1))) {
        fprintf(stderr, "int overflow!\n");
        exit(-1);
    }

    result = sint1 / sint2;
    printf("result = %d\n", result);

    return 0;
}

#endif

