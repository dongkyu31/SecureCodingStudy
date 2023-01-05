/* 
 * INT-09. 비트 연산자는 unsigned 피연산자에만 사용해라
 *
 * 비트 연산자(~, >>, <<, &, |, ^)는 signed  정수에 대한 비트 연산이 구현마다
 * 다르게 정의되어 있기 때문에 unsigned 정수 피연산자에 대해서만 사용해야 한다.
 */

#if 1
// 위험한 코드
// 부호 있는 정수의 오른 쪽 시프트 연산은 컴파일러에 따라 비어 있는
// 비트가 0 또는 부호 비트로 채워질 수 있다. 따라서 다음의 코드는 경우에 
// 따라서 버퍼 오버플로가 발생할 수 있따.

#include <stdio.h>

int main() {
    int packet = 0x80000000;
    
    printf("%x", packet >> 24); // 0xFFFFFF80
    return 0;
}
#endif

#if 0
// 해결 방법
// 부호 없는 정수를 사용하면 비어 있는 비트가 0으로 채워지게 되므로 
// 오버플로가 발생하지 않는다.
#include <stdio.h>

int main() {
    unsigned int packet = 0x80000000;

    printf("%x", packet >> 24); // 0x80
    return 0;
}
#endif
