/*
 * INT-12. 음수나 피연산자의 비트보다 더 많은 비트를 시프트하지 마라
 *
 * 오른쪽 피연산자의 값이 음수 또는 승계된 왼쪽 피연산자의 값과 같거나 
 * 큰 경우 정의되지 않은 동작이 일어난다.
 */

#if 0
// 위험한 코드 1.
// 오른쪽 피연산자의 값이 음수이므로 다음의 코드는 미정의 동작이다.
#include <stdio.h>
#include <limits.h>

int main() {
    signed char sint1, sint2, result = 0;
    sint1 = 1;
    sint2 = -1;

    result = sint1 << sint2;
    printf("result = %d\n", result);

    return 0;
}
#endif 

#if 0
// 해결 방법
// 오른쪽 피연산자가 음수인지 검사한다.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    signed char sint1, sint2, result = 0;
    sint1 = 1;
    sint2 = -1;

    if (sint2 < 0) {
        fprintf(stderr, "undefined behavior!\n");
        exit(-1);
    }

    result = sint1 << sint2;
    printf("result = %d\n", result);

    return 0;
}
#endif 

#if 0
// 위험한 코드 2.
// 피연산자으 비트보다 더 많은 비트를 시프트하는 것은 미정의 동작이다.
#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int uint1, uint2, result;
    uint1 = 1;
    uint2 = 32;

    result = uint1 << uint2;
    printf("result = %u\n", result);

    return 0;
}

#endif 

#if 0
// 해결 방법
// 시프트 연산을 수행하기 전에 검사를 수행한다.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INT_BIT (sizeof(unsigned int) * CHAR_BIT)

int main() {
    unsigned int uint1, uint2, result;
    uint1 = 1;
    uint2 = 32;

    if (uint2 >= INT_BIT) {
        fprintf(stderr, "undefined behavior!\n");
        exit(-1);
    }

    result = uint1 << uint2;
    printf("result = %u\n", result);

    return 0;
}
#endif 



