/*
 * FLP-04. 부동소수점 연산용 정수는 먼저 부동소수점으로 바꿔라.
 *
 * 계산시 정수를 사용해 부동소수점 변수에 값을 할당하는 경우 정보가 손실될 수 있다.
 * 이 경우 표현식의 정수 중 하나를 부동 소수점 타입으로 변환해 피할 수 있다.
 *
 */

#if 1
// 위험한 코드
#include <stdio.h>

int main() {
    short a = 533;
    int b = 6789;
    long c = 466438237;

    float d = a / 7;    // d는 76.0
    printf("d : %f\n", d);

    double e = b / 30;  // e는 226.0
    printf("d : %f\n", e);

    double f = c * 789; // f는 오버플로우되어 음수일 수 있다.
    printf("d : %f\n", f);

    return 0;
}
#endif 

#if 0
// 해결 방법 1.
#include <stdio.h>

int main() {
    short a = 533;
    int b = 6789;
    long c = 466438237;

    float d = a / 7.0f;
    printf("d : %f\n", d);

    double e = b / 30.0;
    printf("d : %f\n", e);

    double f = (double)c * 789;
    printf("d : %f\n", f);

    return 0;
}
#endif 

#if 0
// 해결 방법 2.
#include <stdio.h>

int main() {
    short a = 533;
    int b = 6789;
    long c = 466438237;

    float d = a;
    d /= 7;
    printf("d : %f\n", d);

    double e = b;
    e /= b;
    printf("d : %f\n", e);

    double f = c;
    f *= 789;
    printf("d : %f\n", f);

    return 0;
}
#endif
