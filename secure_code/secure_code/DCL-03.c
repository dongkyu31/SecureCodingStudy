/*
 * DCL-03. 상수 수식의 값을 테스트할 때는 정적 어썰썬(static assertion)을 사용해라
 *
 * 어썰션은 취약성이 될 수 있는 소프트웨어의 결점을 찾아 제거하는데 사용되는
 * 효과적인 진단 도구이다. 다만, 일반적인 어썰션(assert())를 사용하는 것은
 * 몇가지 제약이 존재하며 다음과 같다.
 *
 * 일반적인 어썰션 도구는 프로그램이 구동 중에 동작하므로 
 * 런타임 오버헤드(overhead)가 존재한다.
 *
 * 일반적인 어썰션 도구의 마지막 동작은 abort 함수를 호출하는 것으로
 * 서버 프로그램이나 임베디드 시스템에서는 사용하기 어렵다.
 */

#if 0
// 문제가 일어나는 콛드
// 구조체를 메모리에 할당할 때 32비트 시스템의 경우 일반적으로 4바이트(32비트)
// 단위로 잡는다. 그렇기 때문에 char, int 하나씩으로 이루어진 구조체라도 
// 5바이트가 아닌 8바이트로 메모리가 잡혀 구조체의 크기는 8바이트로 잡힌다.
//
#include <stdio.h>
#include <assert.h>

typedef struct _Packet {
    char cmd;
    int  len;
} Packet;

int main() {
	printf("sizeof(Packet) = %lu\n", sizeof(Packet));
    assert(sizeof(Packet) == 5);

    Packet data;
    // ...

    return 0;
}
#endif


#if 0
// 해결 방법
// pragma pack() 을 이용하여 메모리 할당을 조절하는 방법이 있다. 
// 이 방식은 네트워크에서 데이터를 전송할 때 사이즈를 줄이기 위한 
// 방법으로 많이 사용되는 기법이다. 
// 그런데 사실 이건 여기서 알려주려는 정적 어썰션과는 관계가 없다. 
// 다만, 이런 방법도 있다는 걸 알아두라는 의미.
#include <stdio.h>
#include <assert.h>

#pragma pack(1) //1 byte 단위로 데이터 메모리를 할당하라는 뜻... 네트워크에서 많이 쓰임
typedef struct _Packet {
    char cmd;
    int  len;
} Packet;

int main() {
	printf("sizeof(Packet) = %lu\n", sizeof(Packet));
    assert(sizeof(Packet) == 5);

    Packet data;
    // ...

    return 0;
}
#endif

#if 1
#include <stdio.h>

#define JOIN_AGAIN(x, y)    x##y
#define JOIN(x, y)  JOIN_AGAIN(x, y)
#define static_assert(e)    \
    typedef char JOIN(assertion_failed_at_line, __LINE__) [(e) ? 1 : -1]

typedef struct _Packet {
    char cmd;
    int  len;
} Packet;

int main() {
	printf("sizeof(Packet) = %lu\n", sizeof(Packet));
    static_assert(sizeof(Packet) == 5);
	// 위 코드는 전처리기에 의해 assertion_failed_at_line83[-1] 로 변환된다. 
	// 그럼 배열의 인자로 -1 은 들어갈 수 없기에 빌드 타임에서 에러가 발생한다.
	// 이렇게 사용하면 런타임이 아닌 빌드 타임에서 에러를 찾을 수 있는 좋은 기법이다.

    Packet data;
    // ...

    return 0;
}

#endif
