/*
 * INT-10. unsigned 정수 연산이 래핑되지 않도록 주의하라.
 *
 * C99 표준에 따르면 unsigned 피연산자를 사용한 계산은 결코 오버플로가
 * 발생하지 않는다. 결과값이 저장될 정수 타입으로 표현될 수 없는 경우
 * 나머지 연산으로 값을 줄여(wrap around) 표현하기 때문이다. 이를 
 * 정수 래핑(wrapping) 이라고 한다. 때문에 신뢰할 수 없는 소스로 부터
 * 얻어진 정수 값이 아래와 같은 곳에 사용된다면 절대 래핑을 허용해서는 안된다.
 *
 *	- 배열의 인덱스
 *	- 포인터 연산의 일부
 *	- 루프 카운터
 *	- 메모리 할당 함수의 인자
 *	- 그 밖의 보안에 민감한 코드
 *
 *
 */

#if 0
// 위험한 코드 1.
// 부호 없는 정수의 덧셈 연산은 정수 래핑이 일어날 수 있기 때문에
// 다음의 코드는 의도하지 않는 결과를 초래할 수 있다.

#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned int uint1, uint2, sum = 0;
    uint1 = UINT_MAX;
    uint2 = 1;

    sum = uint1 + uint2;
    printf("sum : %u\n", sum);

    return 0;
}
#endif 

#if 0
// 해결 방법
// 정수 래핑이 발생하기 전에 미리 테스트한다. 
#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned int uint1, uint2, result = 0;
    uint1 = UINT_MAX;
    uint2 = 1;

    if (uint1 > UINT_MAX - uint2) {
		// 조건문에 수식을 그대로 넣으면 이미 래핑이 될 수 있기에 우변으로 이항해서 체크해야 한다.
        fprintf(stderr, "int wrapping!\n");
        exit(-1);
    }
    result = uint1 + uint2;
    printf("result = %u\n", result);

    return 0;
}
#endif 

#if 0
// 위험한 코드 2.
// 부호 없는 정수의 뺄셈 연산은 정수 래핑이 일어날 수 있기 때문에 
// 다음의 코드는 의도하지 않는 결과를 초래할 수 있다.
#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned int uint1, uint2, result = 0;
    uint1 = 0;
    uint2 = 1;

    result = uint1 - uint2;
    printf("result = %u\n", result);

    return 0;
}
#endif 

#if 0
// 해결 방법
// 정수 래핑이 발생하기 전에 미리 테스트한다.
#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned int uint1, uint2, result = 0;
    uint1 = 0;
    uint2 = 1;

    if (uint1 < uint2) {
		// 조건문에 수식을 그대로 넣으면 이미 래핑이 될 수 있기에 우변으로 이항해서 체크해야 한다.
        fprintf(stderr, "int wrapping!\n");
        exit(-1);
    }

    result = uint1 - uint2;
    printf("result = %u\n", result);

    return 0;
}
#endif

#if 0
// 위험한 코드 3.
// 부호 없는 정수의곱센 연산은 정수 래핑이 일어날 수 있기 때문에 다음의 코드는
// 의도하지 않는 결과를 초래할 수 있다.
#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int uint1, uint2, result = 0;
    uint1 = UINT_MAX;
    uint2 = 2;

    result = uint1 * uint2;
    printf("result = %u\n", result);

    return 0;
}
#endif 

#if 1
// 해결 방법
// 정수 래핑이 발생하기 전에 미리 테스트한다. 
#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int uint1, uint2, result = 0;
    uint1 = UINT_MAX;
    uint2 = 2;

    if (uint1 > UINT_MAX / uint2) {
        fprintf(stderr, "int wrapping!\n");
        exit(-1);
    }

    result = uint1 * uint2;
    printf("result = %u\n", result);

    return 0;
}
#endif 
