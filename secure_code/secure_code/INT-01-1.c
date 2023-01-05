/*
 * INT-01. 구현 시 사용되는 데이터 모델을 이해하라.
 *
 * 데이터 모델(data model)은 표준 데이터 타입에 할당되는 크기를 정의한다.
 * 사용하는 아키텍쳐의 데이터 모델을 이해하는 것은 중요하다.
 *
 * -----------------------------------------------------------------------------------------
 * | Data Type | iAPX86 | IA-32 | IA-64 | SPARC-64 | ARM-32 | Alpha | 64-bit Linux, FreeBSD |
 * |           |        |       |       |          |        |       | NetBSD, and OpenBSD   |
 * ------------------------------------------------------------------------------------------
 * | char      |      8 |     8 |     8 |        8 |      8 |     8 |                     8 |
 * | short     |     16 |    16 |    16 |       16 |     16 |    16 |                    16 |
 * | int       |     16 |    32 |    32 |       32 |     32 |    32 |                    32 |
 * | long      |     32 |    32 |    32 |       64 |     32 |    64 |                    64 |
 * | long long |    N/A |    64 |    64 |       64 |     64 |    64 |                    64 |
 * | Pointer   |  16/32 |    32 |    64 |       64 |     32 |    64 |                    64 |
 * ------------------------------------------------------------------------------------------
 *
 *
 *
 *
 * 또한 주어진 타입에 대한 범위를 가정하기 보다는 limits.h 파일을 사용하는 것이 더 좋다. 
 * limits.h 파일 안에는 모든 일치하는 플랫폼에 대한 표준 정수 타입의 범위를 결정하는
 * 매크로를 가지고 있으며 예는 다음과 같다.
 *
 *  ▪ UINT_MAX: unsigned int가 가질 수 있는 최대값
 *  ▪ LONG_MIN: long int가 가질 수 있는 최소값
 *
 *  추가적으로 stdint.h 파일에는 특정한 데이터 모델에 종속되지 않고 사용할 수 있는
 *  특정 크기로 제한된 타입들이 있으며 예는 다음과 같다. 
 *  
 *  ▪ int_least_32_t: 플랫폼에서 지원하는 최소 32비트 이상을 가진 부호 있는 정수 타입
 *  ▪ uint_fast16_t: 최소 16비트 이상을 갖는 부호 없는 정수 타입 중 플랫폼에서 지원하는 가장 빠른 타입
 *
 *
 */


#if 0
// 위험한 코드 1.
// 다음 코드는 sizeof(int) == sizeof(long) 인 플랫폼에서는 정확하게 동작하지만, 
// 그렇지 않은 경우 버퍼 오버 플로우가 발생 함.
#include <stdio.h>

int main() {
    int input;

    if (scanf("%ld", &input) < 1) {
        perror("scanf");
        return -1;
    }

    printf("%d\n", input);
    return 0;
}
#endif 

#if 0
// 해결 방법
// 사용하는 타입과 맞는 정확한 포맷을 사용
#include <stdio.h>

int main() {
    int input;

    if (scanf("%d", &input) < 1) {
        perror("scanf");
        return -1;
    }

    printf("%d\n", input);
    return 0;
}
#endif 

#if 0
// 위험한 코드 2.
// 다음 코드에서는 unsigned int 값 두개를 모든 비트가 유지될 것이라고 가정하고 있다.
// 그러나 이 코드는 64비트 리눅스 플랫폼에서는 정상 동작하지만 윈도우즈 플랫폼에서는
// 실패할 수 있다.

#include <stdio.h>

int main() {
    unsigned int a, b;
    unsigned long c;

    a = 1000000000;
    b = 10;
    c = (unsigned long)a * b;
    printf("c = %lu\n", c);

    return 0;
}
#endif 

#if 0
// 해결 방법
// 결과를 보존할 수 있는 큰 타입을 사용한다.
#include <stdio.h>
#include <stdint.h> // uintmax_t

int main() {
    unsigned int a, b;
    uintmax_t c;

    a = 1000000000;
    b = 10;
    c = (uintmax_t)a * b;
    printf("c = %llu\n", c);

    return 0;
}
#endif 
