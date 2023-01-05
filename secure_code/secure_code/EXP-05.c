/*
 * EXP-05. 포인터 연산이 정확하게 수행되고 있는지 보장하라.
 *
 * 포인터 연산을 수행할 때 포인터에 더해지는 값은 자동적으로 포인터가 가리키는 객체의
 * 타입으로 조정된다. 때문에 포인터 연산이 어떻게 동작하는지 이해하고 있지 않는다면
 * 심각한 에러나 버퍼 오버플로를 초래한다.
 *
 * 어떤 포인터 ptr과 임의의 정수 n이 있을 때, 포인터 연산은 내부적으로 다음과 같이 
 * 동작한다.
 *
 *     - ptr +n == ptr + (sizeof(*ptr) * n)
 *
 */
#if 1
// 위험한 코드
// 다음 코드는 버퍼 오버플로가 발생한다.
#include <stdio.h>
#define BUF_SIZE    (10)

int main() {
    int buf[BUF_SIZE];

    int* cur = buf;
    while (cur < (buf + sizeof(buf))) {
		printf("sizeof(buf) is (%ld), cur is (%d)\n", sizeof(buf), cur);
        *cur++ = 0;
	}

    for (int i = 0; i < BUF_SIZE; i++)
        printf("buf[%d] = %d\n", i, buf[i]);

    return 0;
}
#endif

#if 0
// 해결 방법 1.
// 포인터 연산 시, 정수의 크기만큼 계산될 수 있도록 char* 타입으로 캐스팅한다.
#include <stdio.h>
#define BUF_SIZE    (10)

int main() {
    int buf[BUF_SIZE];

    int* cur = buf;
    while (cur < ((char*)buf + sizeof(buf))) {
		//printf("sizeof(buf) is (%ld), cur is (%ld)\n", sizeof(buf), cur);
		printf("sizeof(buf) is (%ld), cur is (%ld)\n", sizeof(buf), cur);
        *cur++ = 0;
	}

    for (int i = 0; i < BUF_SIZE; i++)
        printf("buf[%d] = %d\n", i, buf[i]);

    return 0;
}
#endif

#if 0
// 해결 방법 2.
// 첨자 연산자를 사용한다.
#include <stdio.h>
#define BUF_SIZE    (10)

int main() {
    int buf[BUF_SIZE];

    for (int i = 0; i < BUF_SIZE; i++)
        buf[i] = 0;

    for (int i = 0; i < BUF_SIZE; i++)
        printf("buf[%d] = %d\n", i, buf[i]);

    return 0;
}
#endif
