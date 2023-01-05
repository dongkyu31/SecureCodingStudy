/* 
 * INT-08. 표현식에서 signed, unsigned 표시가 없는 int 비트 필드의 타입을 가정하지 마라.
 *
 * 비트 필드에서 정수 타입이 부호가 있는 정수 타입인지 아닌지는 구현마다 다르다. 
 * C99 표준에 따르면 "만일 int 타입으로 승계될 때, 원래 타입의 모든 값을 표현할 수 있다면 
 * 값은 int로 변환되면 그렇지 않은 경우 unsigned int 로 변환된다"라고 되어 있다.
 */
#if 1
// 위험한 코드
// 비트 필드에서 int 비트 필드를 지정하면 구현에 따라 그 값(-1 또는 255)이 달라질 수 있다.

#include <stdio.h>

struct {
    int a : 8;
} bits = { 255 };

int main() {
    printf("bits.a = %d\n", bits.a);
    return 0;
}
#endif 

#if 0
// 해결 방법
// 부호의 유무를 명시적으로 선언하면 의도가 명확해진다.
#include <stdio.h>

struct {
    unsigned int a : 8;
} bits = { 255 };

int main() {
    printf("bits.a = %d\n", bits.a);
    return 0;
}
#endif 
